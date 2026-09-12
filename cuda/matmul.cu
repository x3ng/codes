#include "cudaCheck.h"

__global__ void matmul(float* A, float* B, float* C, int M, int N, int K) {
  assert(blockDim.x == blockDim.y);
  const int TS = blockDim.x;
  const int MO = TS * TS;
  extern __shared__ float mem[];
  int row = blockIdx.y * TS + threadIdx.y;
  int col = blockIdx.x * TS + threadIdx.x;
  float cv = 0.0f;
  for (int s=0; s<(K+TS-1)/TS; ++s) {
    mem[threadIdx.y*TS+threadIdx.x] = row<M&&(s*TS+threadIdx.x)<K ? A[row*K+s*TS+threadIdx.x] : 0.0f;
    mem[MO+threadIdx.y*TS+threadIdx.x] = (s*TS+threadIdx.y)<K&&col<N ? B[(s*TS+threadIdx.y)*N+col] : 0.0f;
    __syncthreads();
    for (int t=0; t<TS; ++t) {
        cv += mem[threadIdx.y*TS+t] * mem[MO+t*TS+threadIdx.x];
    }
  }  
  if (row<M && col<N) {
    C[row*N+col] = cv;
  }
}

int main() {
  int K = 128;
  int M = 256;
  int N = 512;
  int tile_size = 32;

  float* A;
  cudaCheck(cudaMalloc(&A, M*K*sizeof(float)));
  float* B;
  cudaCheck(cudaMalloc(&B, K*N*sizeof(float)));
  float* C;
  cudaCheck(cudaMalloc(&C, M*N*sizeof(float)));

  dim3 block(tile_size, tile_size);
  dim3 grid((N+block.x-1)/block.x, (M+block.y-1)/block.y);
  size_t sm = 2 * tile_size * tile_size * sizeof(float);

  matmul<<<grid, block, sm>>>(A, B, C, M, N, K);
  cudaCheck(cudaDeviceSynchronize());

  cudaFree(A);
  cudaFree(B);
  cudaFree(C);

  return 0;
}
