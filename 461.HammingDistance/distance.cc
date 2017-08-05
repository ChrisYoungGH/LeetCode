class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x ^ y;
        int d = 0;
        while (z != 0) {
            d += z % 2;
            z /= 2;
        }
        return d;
    }
};
