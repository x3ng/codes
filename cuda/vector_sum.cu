#include <cmath>
#include <cuda_runtime.h>

#include "cuda_check.h"

__global__ void vectorSum(float *V, int N) {
  extern __shared__ float sd[];
  unsigned int tid = threadIdx.x;
  unsigned int idx = blockIdx.x * blockDim.x + threadIdx.x;

  sd[tid] = idx < N ? V[idx] : 0.f;
  __syncthreads();

  for (int s = blockDim.x / 2; s > 0; s >>= 1) {
    if (tid < s) {
      sd[tid] += sd[tid + s];
    }
    __syncthreads();
  }

  if (tid == 0) {
    V[blockIdx.x] = sd[0];
  }
}

int main() {
  const int N = 1 << 20;
  const size_t size = N * sizeof(float);

  float *hv;
  float *hr;
  hr = (float *)malloc(sizeof(float));
  hv = (float *)malloc(size);
  for (int i = 0; i < N; ++i) {
    hv[i] = sinf(i * 0.01f);
  }
  for (int i = 0; i < N; ++i) {
    *hr += hv[i];
  }

  float *dv;
  float *dr;
  dr = (float *)malloc(sizeof(float));
  CUDA_CHECK(cudaMalloc(&dv, size));
  CUDA_CHECK(cudaMemcpy(dv, hv, size, cudaMemcpyHostToDevice));

  int block = 256;
  int grid;

  int cn = N;

  while (cn != 1) {
    grid = (cn + block - 1) / block;
    vectorSum<<<grid, block, block * sizeof(float)>>>(dv, cn);
    cn = grid;
  }

  CUDA_CHECK(cudaMemcpy(dr, dv, sizeof(float), cudaMemcpyDeviceToHost));

  if (fabsf(*hr - *dr) > 1e-5f) {
    printf("verification failed\n");
  } else {
    printf("verification pass\n");
  }

  cudaFree(dv);

  free(hv);
  free(hr);
  free(dr);

  return 0;
}
