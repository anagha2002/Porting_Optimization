
#include <iostream>
#include "ParametricEQ.h"

int main() {
    ParametricEQ eq;
    eq.setPeakingParams(48000, 1000, 6.0, 0.707);

    for (int i = 0; i < 64; ++i) {
        float x = (i == 0) ? 1.0f : 0.0f;
        float y = eq.process(x);
        std::cout << y << std::endl;
    }
    return 0;
}
