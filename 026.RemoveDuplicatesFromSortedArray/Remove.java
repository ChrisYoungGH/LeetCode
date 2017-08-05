public class Remove {
    // 方法1: 只判断与新尾端相不相等，不相等则新尾端增加并改变值
    public int removeDuplicates(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }

        int newTail = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != nums[newTail]) {
                newTail++;
                nums[newTail] = nums[i];
            }
        }

        return newTail + 1;
    }

    // 方法3：统计重复数，每遇到一个不重复的则写到其原来位置，即当前位置减去总重复数
    // 比较重复时与前一个数比较
    public int removeDuplicates2(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }

        int nDups = 0;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] == nums[i-1]) {
                nDups++;
            }
            else {
                nums[i - nDups] = nums[i];
            }
        }

        return nums.length - nDups;
    }

    public static void main(String[] args) {
        int[] nums = new int[] {1,1,1,2,3,4,5,5,5,5,6};
        System.out.println(new Remove().removeDuplicates2(nums));
    }
}
