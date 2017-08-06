#include <iostream>

class Solution {
public:
    int mySqrt(int x) {
        long long low = 0, high = x;
        long long square = 0, mid = 0;
        while (low <= high) {
            mid = (low + high) / 2;
            square = mid * mid;
            if (square == x) {
                return int(mid);
            }
            if (square > x) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return int(square <= x ? mid : mid-1);
    }
};

int main(int argc, char const *argv[]) {
    std::cout << (Solution()).mySqrt(2147395599) << std::endl;
    return 0;
}
