class Solution {
    public int minMoves(int[] nums) {
        int sum = 0, min = nums[0];
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
            min = Math.min(min, nums[i]);
        }
        return sum - min * nums.length;
    }
}
