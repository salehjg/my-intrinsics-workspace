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

    return 0;
}