#include<cmath>

class Solution {
public: 
    int jumpFloorII(int n) {
        return n > 0 ? pow(2, n-1) : 0;
    }
};