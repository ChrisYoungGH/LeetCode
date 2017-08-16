import java.lang.Math;

public class Max {
    public int findMaxConsecutiveOnes(int[] nums) {
        int maxLen = 0;
        int len = 0;
        boolean flag = false;

        for (int n : nums) {
            if (n == 1) {
                if (flag == false) {
                    flag = true;
                }
                len++;
            }
            else {
                maxLen = Math.max(maxLen, len);
                len = 0;
            }
        }
        return Math.max(maxLen, len);
    }

    public static void main(String[] args) {
        int[] nums = {1,1,0,0,0,1,1,1,1};
        System.out.println(new Max().findMaxConsecutiveOnes(nums));
    }
}
