#include <climits>

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long max1 = LONG_MIN, max2 = LONG_MIN, max3 = LONG_MIN;
        for (int i = 0; i < int(nums.size()); i++) {
            if (nums[i] > max1) {
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            }
            else if (nums[i] == max1) {
                continue;
            }
            else if (nums[i] > max2) {
                max3 = max2;
                max2 = nums[i];
            }
            else if (nums[i] == max2) {
                continue;
            }
            else if (nums[i] > max3) {
                max3 = nums[i];
            }
        }

        if (max3 > LONG_MIN) {
            return int(max3);
        }
        return int(max1);
    }
};
