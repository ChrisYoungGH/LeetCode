class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i = 0; i < int(nums.size()); i += 2) {
            sum += nums[i];
        }
        return sum;
    }
};
