#include "cuda_check.h"
#include <assert.h>

__global__ void matmul1(float *A, float *B, float *C, int M, int N, int K) {
  assert(blockDim.x == blockDim.y);
  const int TS = blockDim.x;
  const int MO = TS * TS;
  extern __shared__ float mem[];
  int row = blockIdx.y * TS + threadIdx.y;
  int col = blockIdx.x * TS + threadIdx.x;
  float cv = 0.0f;
  for (int s = 0; s < (K + TS - 1) / TS; ++s) {
    mem[threadIdx.y * TS + threadIdx.x] =
        row < M && (s * TS + threadIdx.x) < K
            ? A[row * K + s * TS + threadIdx.x]
            : 0.0f;
    mem[MO + threadIdx.y * TS + threadIdx.x] =
        (s * TS + threadIdx.y) < K && col < N
            ? B[(s * TS + threadIdx.y) * N + col]
            : 0.0f;
    __syncthreads();
    for (int t = 0; t < TS; ++t) {
      cv += mem[threadIdx.y * TS + t] * mem[MO + t * TS + threadIdx.x];
    }
  }
  if (row < M && col < N) {
    C[row * N + col] = cv;
  }
}

template <int BM, int BN, int BK, int TM, int TN>
__global__ void matmul2(const float *A, const float *B, float *C, const int M,
                        const int N, const int K) {
  __shared__ float As[BM][BK];
  __shared__ float Bs[BK][BN];

  int thread_y = threadIdx.y;
  int thread_x = threadIdx.x;
  int block_y = blockIdx.y;
  int block_x = blockIdx.x;

  int block_size = blockDim.x * blockDim.y;

  int block_r = block_y * BM;
  int block_c = block_x * BN;
  int thread_r = thread_y * TM;
  int thread_c = thread_x * TN;

  float At[TM];
  float Bt[TN];
  float Ct[TM][TN] = 0.0f;

  for (int bk = 0; bk < K; bk += BK) {
    int bid = blockDim.x * thread_y + thread_x;
    for (int i = bid; i < BM * BK; i += block_size) {
      int sr = i / BK;
      int sc = i % BK;
      int gr = block_r + sr;
      int gc = bk + sc;
      As[sr][sc] = (gr < M && gc < K) ? A[gr * K + gc] : 0.0f;
    }
    for (int i = bid; i < BK * BN; i += block_size) {
      int sr = i / BN;
      int sc = i % BN;
      int gr = bk + sr;
      int gc = block_c + sc;
      Bs[sr][sc] = (gr < K && gc < N) ? B[gr * N + gc] : 0.0f;
    }
    __syncthreads();
    for (int tk = 0; tk < BK; ++tk) {
#pragma unroll
      for (int i = 0; i < TM; ++i) {
        At[i] = As[thread_r + i][tk];
      }
#pragma unroll
      for (int i = 0; i < TN; ++i) {
        Bt[i] = Bs[tk][thread_c + i];
      }
#pragma unroll
      for (int i = 0; i < TM; ++i) {
#pragma unroll
        for (int j = 0; j < TN; ++j) {
          Ct[i][j] += At[i] * Bt[j];
        }
      }
    }
    __syncthreads();
  }
  for (int i = 0; i < TM; ++i) {
    for (int j = 0; j < TN; ++j) {
      int gr = block_r + thread_r + i;
      int gc = block_c + thread_c + j;
      if (gr < M && gc < N) {
        C[gr * N + gc] = Ct[i][j];
      }
    }
  }
}

int main() {
  int K = 128;
  int M = 256;
  int N = 512;
  int tile_size = 32;

  float *A;
  CUDA_CHECK(cudaMalloc(&A, M * K * sizeof(float)));
  float *B;
  CUDA_CHECK(cudaMalloc(&B, K * N * sizeof(float)));
  float *C;
  CUDA_CHECK(cudaMalloc(&C, M * N * sizeof(float)));

  dim3 block(tile_size, tile_size);
  dim3 grid((N + block.x - 1) / block.x, (M + block.y - 1) / block.y);
  size_t sm = 2 * tile_size * tile_size * sizeof(float);

  matmul1<<<grid, block, sm>>>(A, B, C, M, N, K);
  CUDA_CHECK(cudaDeviceSynchronize());

  cudaFree(A);
  cudaFree(B);
  cudaFree(C);

  return 0;
}
