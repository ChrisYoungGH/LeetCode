class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count1 = 0, count2 = 0;
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            count1 += nums[i] > nums[i+1] ? 1 : 0;
            count2 += nums[i] > nums[i+2] ? 1 : 0;
            if (count1 > 1 || count2 > 1) {
                return false;
            }
        }
        if (n >= 2) {
            count1 += nums[n-2] > nums[n-1] ? 1: 0;
        }
        if (count1 > 1 || count2 > 1) {
                return false;
        }
        return true;
    }
};
