//
// Created by saleh on 22/05/24.
//

#include "common/common.h"
#include "common/timer.h"
#include <immintrin.h>

void examplesSimpleAdd() {
    logger->info("Simple AVX2 additions");

    // Single-precision addition
    __m256 float_vec_0 = _mm256_set1_ps(8.0);
    __m256 float_vec_1 = _mm256_set1_ps(17.0);

    __m256 float_result = _mm256_add_ps(float_vec_0, float_vec_1);

    auto* flo = (float*) &float_result;
    logger->info("\tfloat:\t\t{}, {}, {}, {}, {}, {}, {}, {}", flo[0], flo[1], flo[2], flo[3], flo[4], flo[5], flo[6], flo[7]);

    // Double-precision addition
    __m256d double_vec_0 = _mm256_set1_pd(8.0);
    __m256d double_vec_1 = _mm256_set1_pd(17.0);

    __m256d double_result = _mm256_add_pd(double_vec_0, double_vec_1);

    auto* dou = (double*) &double_result;
    logger->info("\tdouble:\t\t{}, {}, {}, {}", dou[0], dou[1], dou[2], dou[3]);

    // 8-bit integer addition (AVX2)
    __m256i epi8_vec_0 = _mm256_set1_epi8(8);
    __m256i epi8_vec_1 = _mm256_set1_epi8(17);

    __m256i epi8_result = _mm256_add_epi8(epi8_vec_0, epi8_vec_1);

    auto* c = (char*) &epi8_result;
    logger->info("\tchar:\t\t");
    for (int i = 0; i < 32; i++) {
        logger->info("\t\t{}, ", c[i]);
    }

    // 16-bit integer addition (AVX2)
    __m256i epi16_vec_0 = _mm256_set1_epi16(8);
    __m256i epi16_vec_1 = _mm256_set1_epi16(17);

    __m256i epi16_result = _mm256_add_epi16(epi16_vec_0, epi16_vec_1);
    auto* sho = (short*) &epi16_result;
    logger->info("\tshort:\t\t");
    for (int i = 0; i < 16; i++) {
        logger->info("\t\t{}, ", sho[i]);
    }

    // 32-bit integer addition (AVX2)
    __m256i epi32_vec_0 = _mm256_set1_epi32(8);
    __m256i epi32_vec_1 = _mm256_set1_epi32(17);
    __m256i epi32_result = _mm256_add_epi32(epi32_vec_0, epi32_vec_1);

    int* i = (int*) &epi32_result;
    logger->info("\tint:\t\t{}, {}, {}, {}, {}, {}, {}, {}", i[0], i[1], i[2], i[3], i[4], i[5], i[6], i[7]);

    // 64-bit integer addition (AVX2)
    __m256i epi64_vec_0 = _mm256_set1_epi64x(8);
    __m256i epi64_vec_1 = _mm256_set1_epi64x(17);
    __m256i epi64_result = _mm256_add_epi64(epi64_vec_0, epi64_vec_1);

    long long int* lo = (long long int*) &epi64_result;
    logger->info("\tlong long:\t{}, {}, {}, {}", lo[0], lo[1], lo[2], lo[3]);
}


int main(int argc, char **argv) {
    timer::reportForLambda<std::nano>([](){
        initLogger();
    });
    examplesSimpleAdd();

    return 0;
}