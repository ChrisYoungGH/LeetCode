class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = int(nums.size()) * (int(nums.size()) + 1) / 2;
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
            sum -= *it;
        }
        return sum;
    }

    int missingNumberOpt(vector<int>& nums) {
        int x = int(nums.size());
        for (int i = 0; i < int(nums.size()); i++) {
            x ^= i ^ nums[i];
        }
        return x;
    }
};
