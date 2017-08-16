#include <cmath>
using namespace std;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxLen = 0;
        int len = 0;
        bool flag = false;

        for (int i = 0; i < int(nums.size()); i++) {
            if (nums[i] == 1) {
                if (flag == false) {
                    flag = true;
                }
                len++;
            }
            else {
                maxLen = max(maxLen, len);
                len = 0;
            }
        }
        return max(maxLen, len);
    }
};
