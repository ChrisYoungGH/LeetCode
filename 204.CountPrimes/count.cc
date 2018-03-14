#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n < 3) {
            return 0;
        }

        // 不能用静态数组
        vector<int> prime(n, 0);
        prime[0] = prime[1] = 1;

        int count = 1;
        int up = sqrt(n);
        // 先去除偶数
        for (int i = 3; i < n; i += 2) {
            if (prime[i] == 0) {
                // 考虑在里面计数
                count++;
                // 跳过大于sqrt(n)的数
                if (i <= up) {
                    for (int j = i*i; j < n; j += i) {
                        prime[j] = 1;
                    }
                }
            }
        }

        return count;
    }
};

int main(int argc, char const *argv[]) {
    Solution s = Solution();
    cout << s.countPrimes(19) << endl;
    return 0;
}
