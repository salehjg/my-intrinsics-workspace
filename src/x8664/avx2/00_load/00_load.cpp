//
// Created by saleh on 22/05/24.
//

#include "common/common.h"
#include "common/timer.h"
#include <immintrin.h>

int main(int argc, char **argv) {
    timer::reportForLambda<std::nano>([](){
        initLogger();
    });

    // Single-precision
    int i;
    auto* aligned_floats = (float*) aligned_alloc(32, 8* sizeof(float));
    for (i = 0; i < 8; i++) {
        aligned_floats[i] = (float)(i) + 1.0f;
    }

    __m256 float_vec = _mm256_load_ps(aligned_floats);

    auto* flo = (float*) &float_vec;
    logger->info("float:\t\t{}, {}, {}, {}, {}, {}, {}, {}", flo[0], flo[1], flo[2], flo[3], flo[4], flo[5], flo[6], flo[7]);


    // Double-precision
    auto* aligned_doubles = (double*) aligned_alloc(32, 4 * 8 * sizeof(double));
    for (i = 0; i < 4; i++) {
        aligned_doubles[i] = (double)(i) + 1.0;
    }

    __m256d double_vec = _mm256_load_pd(aligned_doubles);

    auto* dou = (double*) &double_vec;
    logger->info("double:\t\t{}, {}, {}, {}", dou[0], dou[1], dou[2], dou[3]);

    // 32-bit Integer
    auto* aligned_int = (int*) aligned_alloc(32, 8 * 8 * sizeof(int));
    for (i = 0; i < 8; i++) {
        aligned_int[i] = i + 1;
    }

    __m256i int_vec = _mm256_load_si256((const __m256i*) aligned_int);

    auto* i_v = (int*) &int_vec;
    logger->info("int:\t\t{}, {}, {}, {}, {}, {}, {}, {}", i_v[0], i_v[1], i_v[2], i_v[3], i_v[4], i_v[5], i_v[6], i_v[7]);

    return 0;
}