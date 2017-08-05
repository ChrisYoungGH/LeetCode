#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for (int i = 0; i < int(nums.size()); i++) {
            if (nums[i] >= target) {
                return i;
            }
        }

        return int(nums.size());
    }
};

int main(int argc, char const *argv[]) {
    Solution s = Solution();
    int numsArr[] = {1,3,5,6};
    vector<int> nums(numsArr, numsArr + 4);
    cout << s.searchInsert(nums, 7) << endl;
    return 0;
}
