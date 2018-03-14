#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        int ans = (int)(sqrt(n) * sqrt(2));
        return (int)((long)ans * (long)(ans + 1) / 2) <= n ? ans : ans - 1;
    }
};

int main(int argc, char const *argv[]) {
    Solution s = Solution();
    cout << s.arrangeCoins(1804289383);
    return 0;
}
