//
// Created by saleh on 22/05/24.
//

#include "common/common.h"
#include "common/timer.h"
#include <immintrin.h>

#include <cstdlib> // for rand() and srand()
#include <ctime>

void examplesSimpleAdd() {
    logger->info("Simple AVX2 additions");

    // Single-precision addition
    __m256 float_vec_0 = _mm256_set1_ps(8.0);
    __m256 float_vec_1 = _mm256_set1_ps(17.0);

    __m256 float_result = _mm256_add_ps(float_vec_0, float_vec_1);

    auto *flo = (float *) &float_result;
    logger->info("\tfloat:\t\t{}, {}, {}, {}, {}, {}, {}, {}", flo[0], flo[1], flo[2], flo[3], flo[4], flo[5], flo[6],
                 flo[7]);

    // Double-precision addition
    __m256d double_vec_0 = _mm256_set1_pd(8.0);
    __m256d double_vec_1 = _mm256_set1_pd(17.0);

    __m256d double_result = _mm256_add_pd(double_vec_0, double_vec_1);

    auto *dou = (double *) &double_result;
    logger->info("\tdouble:\t\t{}, {}, {}, {}", dou[0], dou[1], dou[2], dou[3]);

    // 8-bit integer addition (AVX2)
    __m256i epi8_vec_0 = _mm256_set1_epi8(8);
    __m256i epi8_vec_1 = _mm256_set1_epi8(17);

    __m256i epi8_result = _mm256_add_epi8(epi8_vec_0, epi8_vec_1);

    auto *c = (char *) &epi8_result;
    logger->info("\tchar:\t\t");
    for (int i = 0; i < 32; i++) {
        logger->info("\t\t{}, ", c[i]);
    }

    // 16-bit integer addition (AVX2)
    __m256i epi16_vec_0 = _mm256_set1_epi16(8);
    __m256i epi16_vec_1 = _mm256_set1_epi16(17);

    __m256i epi16_result = _mm256_add_epi16(epi16_vec_0, epi16_vec_1);
    auto *sho = (short *) &epi16_result;
    logger->info("\tshort:\t\t");
    for (int i = 0; i < 16; i++) {
        logger->info("\t\t{}, ", sho[i]);
    }

    // 32-bit integer addition (AVX2)
    __m256i epi32_vec_0 = _mm256_set1_epi32(8);
    __m256i epi32_vec_1 = _mm256_set1_epi32(17);
    __m256i epi32_result = _mm256_add_epi32(epi32_vec_0, epi32_vec_1);

    int *i = (int *) &epi32_result;
    logger->info("\tint:\t\t{}, {}, {}, {}, {}, {}, {}, {}", i[0], i[1], i[2], i[3], i[4], i[5], i[6], i[7]);

    // 64-bit integer addition (AVX2)
    __m256i epi64_vec_0 = _mm256_set1_epi64x(8);
    __m256i epi64_vec_1 = _mm256_set1_epi64x(17);
    __m256i epi64_result = _mm256_add_epi64(epi64_vec_0, epi64_vec_1);

    long long int *lo = (long long int *) &epi64_result;
    logger->info("\tlong long:\t{}, {}, {}, {}", lo[0], lo[1], lo[2], lo[3]);
}

float example1_baseline(float *buff1, int *indices, int lenIndices) {
    logger->info("Example1 Baseline");
    float sum=0;
    timer::reportForLambda([&]() {
        for (int i = 0; i < lenIndices; i++) {
            sum += buff1[indices[i]];
        }
    });
    logger->info("Sum: {}", sum);
    return sum;
}

float example1_intrinsics1(float *buff1, int *indices, int lenIndices) {
    logger->info("Example1 Baseline");
    float r=0;
    timer::reportForLambda([&](){
        __m256 sum = _mm256_setzero_ps();
        for (int i = 0; i < lenIndices/8; i++) {
            __m256i vindex = _mm256_loadu_si256((__m256i*)(&indices[i*8]));

            __m256 vec = _mm256_i32gather_ps(buff1, vindex, 4); // 4 because sizeof(float) = 4
            sum = _mm256_add_ps(sum, vec);
        }
        r = ((float*)&sum)[0] + ((float*)&sum)[1] + ((float*)&sum)[2] + ((float*)&sum)[3] + ((float*)&sum)[4] + ((float*)&sum)[5] + ((float*)&sum)[6] + ((float*)&sum)[7];
    });

    logger->info("Sum: {}", r);
    return r;
}

int getRandom(int n) {
    srand(time(0)); // use current time as seed for random generator
    return rand() % (n + 1);
}

void example1 () {
    int len = 8000;
    float *buff1 = new float[len];
    int *indices = new int[len];
    for (int i = 0; i < len; i++) {
        buff1[i] = i;
        indices[i] = getRandom(len);
    }

    example1_baseline(buff1, indices, len);
    example1_intrinsics1(buff1, indices, len);

}

int main(int argc, char **argv) {
    timer::reportForLambda<std::nano>([]() {
        initLogger();
    });
    examplesSimpleAdd();
    example1();
    return 0;
}