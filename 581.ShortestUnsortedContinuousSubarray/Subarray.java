public class Solution {
    public int findUnsortedSubarray(int[] nums) {
        int[] sortedNums = nums.clone();
        Arrays.sort(sortedNums);

        int n = nums.length;
        int begin = 0, end = n-1;

        while (begin < end) {
            if (nums[begin] == sortedNums[begin]) {
                begin++;
            }
            else {
                break;
            }
        }

        while (end > begin) {
            if (nums[end] == sortedNums[end]) {
                end--;
            }
            else {
                break;
            }
        }

        int len = end - begin + 1;
        return len != 1 ? len : 0;
    }

    public int findUnsortedSubarray2(int[] nums) {
        int n = nums.length;
        int begin = -1, end = -2;
        int max = nums[0], min = nums[n-1];

        for (int i = 1; i < n; i++) {
            max = Math.max(max, nums[i]);
            min = Math.min(min, nums[n-i-1]);

            end = nums[i] < max ? i : end;
            begin = nums[n-i-1] > min ? n-i-1 : begin;
        }

        return end - begin + 1;
    }
}
