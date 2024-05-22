//
// Created by saleh on 22/05/24.
//

#include "common/common.h"
#include "common/timer.h"
#include <immintrin.h>


void examplesInitPacksImmediate() {
    logger->info("Initializing AVX2 packs with immediate values");
    __m256 float_vec2 = _mm256_set1_ps(123.0f);
    auto* flo2 = (float*) &float_vec2;
    logger->info("\tfloat:\t\t{}, {}, {}, {}, {}, {}, {}, {}", flo2[0], flo2[1], flo2[2], flo2[3], flo2[4], flo2[5], flo2[6], flo2[7]);

    __m256 float_vec3 = _mm256_set_ps(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f);
    auto* flo3 = (float*) &float_vec3;
    logger->info("\tfloat:\t\t{}, {}, {}, {}, {}, {}, {}, {}", flo3[0], flo3[1], flo3[2], flo3[3], flo3[4], flo3[5], flo3[6], flo3[7]);

    __m256 float_vec4 = _mm256_setr_ps(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f);
    auto* flo4 = (float*) &float_vec4;
    logger->info("\tfloat:\t\t{}, {}, {}, {}, {}, {}, {}, {}", flo4[0], flo4[1], flo4[2], flo4[3], flo4[4], flo4[5], flo4[6], flo4[7]);

}

void examplesInitPacksFromMemory() {
    logger->info("Initializing AVX2 packs from memory");
    // Single-precision
    int i;
    auto* aligned_floats = (float*) aligned_alloc(32, 8* sizeof(float));
    for (i = 0; i < 8; i++) {
        aligned_floats[i] = (float)(i) + 1.0f;
    }

    __m256 float_vec = _mm256_load_ps(aligned_floats);
    auto* flo = (float*) &float_vec;
    logger->info("\tfloat:\t\t{}, {}, {}, {}, {}, {}, {}, {}", flo[0], flo[1], flo[2], flo[3], flo[4], flo[5], flo[6], flo[7]);

    // Double-precision
    auto* aligned_doubles = (double*) aligned_alloc(32, 4 * 8 * sizeof(double));
    for (i = 0; i < 4; i++) {
        aligned_doubles[i] = (double)(i) + 1.0;
    }
    __m256d double_vec = _mm256_load_pd(aligned_doubles);
    auto* dou = (double*) &double_vec;
    logger->info("\tdouble:\t\t{}, {}, {}, {}", dou[0], dou[1], dou[2], dou[3]);

    // 32-bit Integer
    auto* aligned_int = (int*) aligned_alloc(32, 8 * 8 * sizeof(int));
    for (i = 0; i < 8; i++) {
        aligned_int[i] = i + 1;
    }
    __m256i int_vec = _mm256_load_si256((const __m256i*) aligned_int);
    auto* i_v = (int*) &int_vec;
    logger->info("\tint:\t\t{}, {}, {}, {}, {}, {}, {}, {}", i_v[0], i_v[1], i_v[2], i_v[3], i_v[4], i_v[5], i_v[6], i_v[7]);

}


int main(int argc, char **argv) {
    timer::reportForLambda<std::nano>([](){
        initLogger();
    });

    examplesInitPacksFromMemory();
    examplesInitPacksImmediate();

    return 0;
}