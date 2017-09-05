class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 1;
        while (i > 0 && nums[i] <= nums[i-1]) {
            i--;
        }
        if (i == 0) {
            sort(nums.begin(), nums.end());
        }
        else {
            int left = i - 1, right = i;
            int minmax = nums[i];
            for (int j = i + 1; j < n; j++) {
                if (nums[j] > nums[left]) {
                    right = j;
                    minmax = min(minmax, nums[j]);
                }
            }

            int tmp = nums[left];
            nums[left] = nums[right];
            nums[right] = tmp;

            sort(nums.begin() + i, nums.end());
            // reverse(nums.begin() + i, nums.end());
        }
    }
};
