public class Solution {
    public int missingNumber(int[] nums) {
        int sum = nums.length * (nums.length + 1) / 2;
        for (int n : nums) {
            sum -= n;
        }
        return sum;
    }

    public int missingNumberOpt(int[] nums) {
        int xor = nums.length;
        for (int i = 0; i < nums.length; i++) {
            xor ^= i ^ nums[i];
        }
        return xor;
    }
}
