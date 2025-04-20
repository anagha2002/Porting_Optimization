
#include <cstdint>
#include <cmath>

class FixedPointEQ {
private:
    int32_t b0, b1, b2, a1, a2;
    int32_t x1 = 0, x2 = 0, y1 = 0, y2 = 0;

public:
    void setCoefficients(int32_t b0_, int32_t b1_, int32_t b2_, int32_t a1_, int32_t a2_) {
        b0 = b0_; b1 = b1_; b2 = b2_;
        a1 = a1_; a2 = a2_;
    }

    int16_t process(int16_t x) {
        int32_t y = (b0 * x + b1 * x1 + b2 * x2 - a1 * y1 - a2 * y2) >> 15;
        x2 = x1;
        x1 = x;
        y2 = y1;
        y1 = y;
        return static_cast<int16_t>(y);
    }
};
