public class Move {
    public void moveZeroes(int[] nums) {
        int nNonZero = 0;
        for (int n : nums) {
            if (n != 0) {
                nums[nNonZero++] = n;
            }
        }
        for (int i = nNonZero; i < nums.length; i++) {
            nums[i] = 0;
        }
    }
}
