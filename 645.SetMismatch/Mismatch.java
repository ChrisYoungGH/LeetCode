class Solution {
    public int[] findErrorNums(int[] nums) {
        int[] counts = new int[nums.length];
        int[] ans = new int[2];
        for (int n : nums) {
            counts[n-1]++;
            if (counts[n-1] > 1) {
                ans[0] = n;
            }
        }
        for (int i = 0; i < counts.length; i++) {
            if (counts[i] == 0) {
                ans[1] = i + 1;
                break;
            }
        }
        return ans;
    }
}
