
#ifndef PARAMETRICEQ_H
#define PARAMETRICEQ_H

class ParametricEQ {
public:
    void setPeakingParams(float fs, float f0, float gain_dB, float Q);
    float process(float x);

private:
    float b0, b1, b2, a1, a2;
    float x1 = 0, x2 = 0, y1 = 0, y2 = 0;
};

#endif
