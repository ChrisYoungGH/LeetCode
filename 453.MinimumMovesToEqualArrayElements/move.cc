class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = 0, minVal = nums[0];
        for (int i = 0; i < int(nums.size()); i++) {
            sum += nums[i];
            minVal = min(minVal, nums[i]);
        }
        return sum - minVal * nums.size();
    }
};
