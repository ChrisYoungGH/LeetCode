class Solution {
    public void nextPermutation(int[] nums) {
        int n = nums.length;
        int i = n - 1;
        while (i > 0 && nums[i] <= nums[i-1]) {
            i--;
        }
        if (i == 0) {
            Arrays.sort(nums);
        }
        else {
            int left = i - 1, right = i;
            int minmax = nums[i];
            for (int j = i + 1; j < n; j++) {
                if (nums[j] > nums[left]) {
                    right = j;
                    minmax = Math.min(minmax, nums[j]);
                }
            }

            int tmp = nums[left];
            nums[left] = nums[right];
            nums[right] = tmp;

            Arrays.sort(nums, i, n);
        }
    }
}
