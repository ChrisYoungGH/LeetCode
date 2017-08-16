#include <cmath>

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int i = 0; i < int(nums.size()); i++) {
            int index = abs(nums[i]) - 1;
            if (nums[index] > 0) {
                nums[index] = -nums[index];
            }
        }

        vector<int> ans;
        for (int i = 0; i < int(nums.size()); i++) {
            if (nums[i] > 0) {
                ans.push_back(i+1);
            }
        }

        return ans;
    }
};
