public class Solution {
    public double findMaxAverage(int[] nums, int k) {
        int sumVal = 0;
        for (int i = 0; i < k; i++) {
            sumVal += nums[i];
        }
        int maxSum = sumVal;
        for (int i = 0; i < nums.length - k; i++) {
            sumVal += -nums[i] + nums[i+k];
            maxSum = Math.max(maxSum, sumVal);
        }

        return (double)maxSum / k;
    }
}
