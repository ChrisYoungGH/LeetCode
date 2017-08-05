#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int nTargets = 0;
        for (unsigned int i = 0; i < nums.size(); i++) {
            if (nums[i] == val) {
                nTargets++;
            }
            else {
                if (nTargets) {
                    nums[i - nTargets] = nums[i];
                }
            }
        }
        
        return nums.size() - nTargets;
    }
};

int main(int argc, char const *argv[]) {
    int numsArr[] = {3,2,2,3};
    vector<int> nums(numsArr, numsArr + 4);
    Solution s = Solution();
    cout << s.removeElement(nums, 3) << endl;
    return 0;
}
