#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) {
            return INT_MIN;
        }

        int maxSubSum = nums[0];
        int sum = nums[0];

        for (int i = 1; i < int(nums.size()); i++) {
            int temp = sum + nums[i];
            sum = nums[i] > temp ? nums[i] : temp;
            maxSubSum = sum > maxSubSum ? sum : maxSubSum;
        }

        return maxSubSum;
    }
};

int main(int argc, char const *argv[]) {
    Solution s = Solution();
    int numsArr[] = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> nums(numsArr, numsArr + 9);
    cout << s.maxSubArray(nums) << endl;
    return 0;
}
