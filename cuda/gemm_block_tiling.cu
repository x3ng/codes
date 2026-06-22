template <int BM, int BN, int BK, int BLOCK_SIZE>
__global__ void gemm_block_tiling(float *A, float *B, float *C, int M, int K,
                                  int N) {
  __shared__ float AS[BM][BK];
  __shared__ float BS[BK][BN];

  int r0 = blockIdx.y * BM;
  int c0 = blockIdx.x * BN;
  int tid = threadIdx.x;

  constexpr int A_BLOCK_X = BK;
  constexpr int A_BLOCK_Y = BLOCK_SIZE / BK;
  int a_thread_x = tid % A_BLOCK_X;
  int a_thread_y = tid / A_BLOCK_X;

  constexpr int B_BLOCK_Y = BK;
  constexpr int B_BLOCK_X = BLOCK_SIZE / BK;
  int b_thread_x = tid % B_BLOCK_X;
  int b_thread_y = tid / B_BLOCK_Y;

  constexpr int C_BLOCK_X = int(sqrt(BLOCK_SIZE));
  constexpr int C_BLOCK_Y = BLOCK_SIZE / C_BLOCK_X;
  constexpr int TM = BM / C_BLOCK_X;
  constexpr int TN = BN / C_BLOCK_Y;
  int c_thread_x = tid % C_BLOCK_X;
  int c_thread_y = tid / C_BLOCK_X;

  float a_frag[TM];
  float b_frag[TN];
  float c_frag[TM][TN] = {0.0f};

  for (int bk = 0; bk < K; bk += BK) {
    for (int i = a_thread_y; i < BM; i += A_BLOCK_Y) {
      int r = r0 + i;
      int c = bk + a_thread_x;
      AS[i][a_thread_x] = (r < M && c < K) ? A[r * K + c] : 0.0f;
    }

    for (int j = b_thread_x; j < BN; j += B_BLOCK_X) {
      int r = bk + b_thread_y;
      int c = c0 + j;
      BS[b_thread_y][j] = (r < K && c < N) ? B[r * N + c] : 0.0f;
    }

    __syncthreads();

    for (int k = 0; k < BK; k += 1) {
      for (int i = 0; i < TM; ++i) {
        int r = c_thread_y * TM;
        a_frag[i] = AS[r + i][k];
      }
      for (int j = 0; j < TN; ++j) {
        int c = c_thread_x * TN;
        b_frag[j] = BS[k][c + j];
      }
      for (int i = 0; i < TM; ++i) {
        for (int j = 0; j < TN; ++j) {
          c_frag[i][j] += a_frag[i] * b_frag[j];
        }
      }
    }
  }

  for (int i = 0; i < TM; ++i) {
    for (int j = 0; j < TN; ++j) {
      C[(r0 + c_thread_y * TM + i) * N + c0 + c_thread_x * TN + j] =
          c_frag[i][j];
    }
  }
}
