public class MaxSubSum {
    public int maxSubArray(int[] nums) {
        if (nums == null || nums.length == 0) {
            return Integer.MIN_VALUE;
        }

        int maxSubSum = nums[0];
        int sum = nums[0];

        for (int i = 1; i < nums.length; i++) {
            int temp = sum + nums[i];
            sum = nums[i] > temp ? nums[i] : temp;
            maxSubSum = sum > maxSubSum ? sum : maxSubSum;
        }

        return maxSubSum;
    }

    public static void main(String[] args) {
        System.out.println(new MaxSubSum().maxSubArray(
            new int[]{-2,1,-3,4,-1,2,1,-5,4}
        ));
    }
}
