// matmul_base.cpp
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <vector>
#include <algorithm>

/*
  BLAS 
    C(m x n) = alpha * op(A) * op(B) + beta * C
    A: (m x k), B: (k x n)
    transa/transb == 'N' or 'T'
 */
void matmul_proj5(char transa, char transb,
                  int64_t m, int64_t n, int64_t k,
                  float alpha, const float* a, int64_t lda,
                  const float* b, int64_t ldb,
                  float beta, float* c, int64_t ldc);

int main(int argc, char** argv) {
  if (argc < 5) {
    std::fprintf(stderr,
      "Usage: %s M N K NUM_ITERS\n"
      "  Example: %s 64 64 64 20\n",
      argv[0], argv[0]);
    return 1;
  }

  int64_t M = std::atoll(argv[1]);
  int64_t N = std::atoll(argv[2]);
  int64_t K = std::atoll(argv[3]);
  int64_t num_iters = std::atoll(argv[4]);

  int64_t sizeA = M * K;
  int64_t sizeB = K * N;
  int64_t sizeC = M * N;

  std::vector<float> A(sizeA), B(sizeB), C(sizeC);

  for (int64_t i = 0; i < sizeA; ++i) {
    A[i] = static_cast<float>((i % 7) + 1);  
  }
  for (int64_t i = 0; i < sizeB; ++i) {
    B[i] = static_cast<float>(((i * 3) % 13) + 1); 
  }
  for (int64_t i = 0; i < sizeC; ++i) {
    C[i] = 0.0f;
  }

  for (int64_t iter = 0; iter < num_iters; ++iter) {
    matmul_proj5('N', 'N',
                 M, N, K,
                 /*alpha=*/1.0f, A.data(), M,
                 B.data(), K,
                 /*beta=*/0.0f, C.data(), M);
  }

  // correctness check
  double checksum = 0.0;
  for (int64_t i = 0; i < sizeC; ++i) {
    checksum += C[i];
  }
  std::printf("Checksum: %.6f\n", checksum);
  return 0;
}

// COMMIT start
// code section to optimize
void matmul_proj5(char transa, char transb,
                  int64_t m, int64_t n, int64_t k,
                  float alpha, const float* a, int64_t lda,
                  const float* b, int64_t ldb,
                  float beta, float* c, int64_t ldc) {
  for (int64_t j = 0; j < n; ++j) {
    for (int64_t i = 0; i < m; ++i) {
      float sum = 0.0f;
      for (int64_t l = 0; l < k; ++l) {
        float elemA = (transa == 'T')
                        ? a[l + i * lda] // lda = M
                        : a[i + l * lda]; 
        float elemB = (transb == 'T')
                        ? b[j + l * ldb] // ldb = K
                        : b[l + j * ldb];
        sum += elemA * elemB;
      }
      // C(i,j) = alpha * sum + beta * C(i,j)
      c[i + j * ldc] = alpha * sum + beta * c[i + j * ldc]; // ldc = M
    }
  }
}
// COMMIT end
