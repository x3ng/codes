#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cuda_runtime.h>
#include <driver_types.h>

#include "cuda_check.h"

__global__ void vectorAdd(const float *A, const float *B, float *C, int N) {
  int idx = blockIdx.x * blockDim.x + threadIdx.x;
  if (idx < N) {
    C[idx] = A[idx] + B[idx];
  }
}

void vectorAddCPU(const float *A, const float *B, float *C, int N) {
  for (int i = 0; i < N; ++i) {
    C[i] = A[i] + B[i];
  }
}

int main() {
  const int N = 1 << 24;
  const size_t size = N * sizeof(float);
  printf("vector size: %d, elements (%.1f MB)\n", N, size / (1024.0 * 1024.0));

  float *ha = (float *)malloc(size);
  float *hb = (float *)malloc(size);
  float *cc = (float *)malloc(size);
  float *cg = (float *)malloc(size);

  for (int i = 0; i < N; ++i) {
    ha[i] = sinf(i * 0.01f);
    hb[i] = cosf(i * 0.01f);
  }

  auto cpu_start = std::chrono::high_resolution_clock::now();
  vectorAddCPU(ha, hb, cc, N);
  auto cpu_end = std::chrono::high_resolution_clock::now();
  float cpu_ms =
      std::chrono::duration<float, std::milli>(cpu_end - cpu_start).count();
  printf("cpu time: %.4f ms\n", cpu_ms);

  float *da;
  float *db;
  float *dc;

  CUDA_CHECK(cudaMalloc(&da, size));
  CUDA_CHECK(cudaMalloc(&db, size));
  CUDA_CHECK(cudaMalloc(&dc, size));

  cudaEvent_t start, stop, kernel_start, kernel_stop;
  cudaEventCreate(&start);
  cudaEventCreate(&stop);
  cudaEventCreate(&kernel_start);
  cudaEventCreate(&kernel_stop);

  cudaEventRecord(start);
  CUDA_CHECK(cudaMemcpy(da, ha, size, cudaMemcpyHostToDevice));
  CUDA_CHECK(cudaMemcpy(db, hb, size, cudaMemcpyHostToDevice));

  int blocksize = 256;
  int gridsize = (N + blocksize - 1) / blocksize;

  cudaEventRecord(kernel_start);
  vectorAdd<<<gridsize, blocksize>>>(da, db, dc, N);
  CUDA_CHECK(cudaGetLastError());
  cudaEventRecord(kernel_stop);

  CUDA_CHECK(cudaMemcpy(cg, dc, size, cudaMemcpyDeviceToHost));
  cudaEventRecord(stop);
  cudaEventSynchronize(stop);

  float gpu_total_ms = 0, kernel_ms = 0;
  cudaEventElapsedTime(&gpu_total_ms, start, stop);
  cudaEventElapsedTime(&kernel_ms, kernel_start, kernel_stop);

  printf("gpu kernel time: %.4f ms\n", kernel_ms);
  printf("gpu total time: %.4f ms\n", gpu_total_ms);

  int errors = 0;
  for (int i = 0; i < N; ++i) {
    if (fabsf(cc[i] - cg[i]) > 1e-5f) {
      if (errors < 5) {
        printf("mismatch at %d: cpu=%.6f, gpu=%.6f\n", i, cc[i], cg[i]);
      }
      ++errors;
    }
  }

  if (errors == 0) {
    printf("verification pass");
  } else {
    printf("verification failed: mismatch %d\n", errors);
  }

  float bwg = (3.0f * size) / (kernel_ms * 1e-3f) / 1e9f;
  printf("effective bandwidth: %.1f GB/s\n", bwg);

  cudaEventDestroy(start);
  cudaEventDestroy(stop);
  cudaEventDestroy(kernel_start);
  cudaEventDestroy(kernel_stop);

  CUDA_CHECK(cudaFree(da));
  CUDA_CHECK(cudaFree(db));
  CUDA_CHECK(cudaFree(dc));

  free(ha);
  free(hb);
  free(cc);
  free(cg);

  return 0;
}
