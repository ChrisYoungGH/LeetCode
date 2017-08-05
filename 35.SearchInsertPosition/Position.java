public class Position {
    public int searchInsert(int[] nums, int target) {
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] >= target) {
                return i;
            }
        }
        return nums.length;
    }

    public static void main(String[] args) {
        int[] nums = new int[] {1,3,5,6};
        int target = 0;
        System.out.println(new Position().searchInsert(nums, target));

    }
}
