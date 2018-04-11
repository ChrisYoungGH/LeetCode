class Solution {
public:
    double Power(double base, int exponent) {
        if (-1e-7 < base && base < 1e-7) {
            if (exponent <= 0) {
                return 0;
            }
        }
        
        return exponent < 0 ?
            1.0 / PowerWithUnsignedExponent(base, -exponent) :
            PowerWithUnsignedExponent(base, exponent);
    }
    
    double PowerWithUnsignedExponent(double base, unsigned int exponent) {
        if (exponent == 0) {
            return 1;
        }
        
        if (exponent == 1) {
            return base;
        }
        
        double curr = (exponent & 0x1) ? base : 1;
        double half = PowerWithUnsignedExponent(base, exponent >> 1);
        
        return curr * half * half;
    }
};