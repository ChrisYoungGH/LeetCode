class Solution {
    public int removeElement(int[] nums, int val) {
        int nTargets = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == val) {
                nTargets++;
            }
            else {
                if (nTargets != 0) {
                    nums[i - nTargets] = nums[i];
                }
            }
        }

        return nums.length - nTargets;
    }

    public static void main(String[] args) {
        int[] nums = new int[] {3,2,2,3,4,3,1};
        System.out.println(new Solution().removeElement(nums, 3));
    }
}
