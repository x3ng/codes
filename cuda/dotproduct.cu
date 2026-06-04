#include <cmath>
#include <cstdlib>

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
__global__ void dotProduct(const float *A, const float *B, float *tmp, int N) {
  extern __shared__ float sd[];
  int tid = threadIdx.x;
  int idx = blockIdx.x * blockDim.x + threadIdx.x;

  sd[tid] = idx < N ? A[idx] * B[idx] : 0.f;
  __syncthreads();

  for (int s = blockDim.x / 2; s > 0; s >>= 1) {
    if (tid < s) {
      sd[tid] += sd[tid + s];
    }
    __syncthreads();
  }

  if (tid == 0) {
    tmp[blockIdx.x] = sd[0];
  }
}

int main() {
  const int N = 1 << 20;
  const size_t size = N * sizeof(float);

  float *ha;
  float *hb;
  float *hr;
  ha = (float *)malloc(size);
  hb = (float *)malloc(size);
  hr = (float *)malloc(sizeof(float));

  for (int i = 0; i < N; ++i) {
    ha[i] = sinf(i * 0.01f);
    hb[i] = cosf(i * 0.01f);
  }

  for (int i = 0; i < N; ++i) {
    *hr += ha[i] * hb[i];
  }

  float *da;
  float *db;
  float *tp;
  float *dr;
  dr = (float *)malloc(sizeof(float));
  *dr = 0.f;
  CUDA_CHECK(cudaMalloc(&da, size));
  CUDA_CHECK(cudaMalloc(&db, size));
  CUDA_CHECK(cudaMemcpy(da, ha, size, cudaMemcpyHostToDevice));
  CUDA_CHECK(cudaMemcpy(db, hb, size, cudaMemcpyHostToDevice));

  int block = 256;
  int grid = (N + block - 1) / block;

  CUDA_CHECK(cudaMalloc(&tp, grid * sizeof(float)));

  int cn = N;
  dotProduct<<<grid, block, block * sizeof(float)>>>(da, db, tp, cn);
  cn = grid;

  while (cn != 1) {
    grid = (cn + block - 1) / block;
    vectorSum<<<grid, block, block * sizeof(float)>>>(tp, cn);
    cn = grid;
  }

  CUDA_CHECK(cudaMemcpy(dr, tp, sizeof(float), cudaMemcpyDeviceToHost));

  if (fabsf(*hr - *dr) > 1e-5f) {
    printf("verification fail\n");
  } else {
    printf("verification pass\n");
  }

  cudaFree(da);
  cudaFree(db);
  cudaFree(tp);

  free(ha);
  free(hb);
  free(hr);
  free(dr);

  return 0;
}
