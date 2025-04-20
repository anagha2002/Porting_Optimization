
#include "ParametricEQ.h"
#include <cmath>

void ParametricEQ::setPeakingParams(float fs, float f0, float gain_dB, float Q) {
    float A = pow(10, gain_dB / 40.0f);
    float omega = 2.0f * M_PI * f0 / fs;
    float alpha = sin(omega) / (2.0f * Q);
    float cos_omega = cos(omega);

    b0 = 1 + alpha * A;
    b1 = -2 * cos_omega;
    b2 = 1 - alpha * A;
    a1 = -2 * cos_omega;
    a2 = 1 - alpha / A;

    float a0 = 1 + alpha / A;
    b0 /= a0;
    b1 /= a0;
    b2 /= a0;
    a1 /= a0;
    a2 /= a0;
}

float ParametricEQ::process(float x) {
    float y = b0 * x + b1 * x1 + b2 * x2 - a1 * y1 - a2 * y2;
    x2 = x1;
    x1 = x;
    y2 = y1;
    y1 = y;
    return y;
}
