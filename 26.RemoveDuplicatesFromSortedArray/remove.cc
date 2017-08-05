#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 方法1: 只判断与新尾端相不相等，不相等则新尾端增加并改变值
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        int newTail = 0;
        for (unsigned int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[newTail]) {
                newTail++;
                nums[newTail] = nums[i];
            }
        }

        return newTail+1;
    }

    // 方法3：统计重复数，每遇到一个不重复的则写到其原来位置，即当前位置减去总重复数
    // 比较重复时与前一个数比较
    int removeDuplicates2(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        int nDups = 0;
        for (unsigned int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1]) {
                nDups++;
            }
            else {
                nums[i - nDups] = nums[i];
            }
        }

        return nums.size() - nDups;
    }
};

int main(int argc, char const *argv[]) {
    int numsArr[] = {1,1,1,2,3,4,5,5,5,5,6};
    vector<int> nums(numsArr, numsArr + 11);
    Solution s = Solution();
    cout << s.removeDuplicates(nums) << endl;
    return 0;
}
