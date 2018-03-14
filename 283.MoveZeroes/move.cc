class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nNonZero = 0;
        for (int i = 0; i < int(nums.size()); i++) {
            if (nums[i] != 0) {
                nums[nNonZero++] = nums[i];
            }
        }
        for (int i = nNonZero; i < int(nums.size()); i++) {
            nums[i] = 0;
        }
    }
};
