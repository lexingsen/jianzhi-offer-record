#include <cmath>

class Solution {
public:
    double Power(double base, int exponent) {
        if (exponent == 0) {
            return 1;
        } else if (exponent == -2147483648) {
            return 0;
        }
        exponent = (long)exponent;
        int sign = 1;
        if (exponent < 0) {
            sign = -1;
            exponent = -exponent;
        }
        double res = 1;
        while (exponent) {
            if (exponent & 1) {
                res = res * base;
            }
            base *= base;
            exponent >>= 1;
        }
        return sign == 1 ? res : 1.0 / res;
    }
};