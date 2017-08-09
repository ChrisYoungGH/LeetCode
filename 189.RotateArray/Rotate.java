import java.util.*;

public class Rotate {
    public void rotate(int[] nums, int k) {
        k %= nums.length;
        if (k == 0) {
            return;
        }
        int[] tmp = new int[k];
        copy(tmp, k, nums, nums.length, k);
        copy(nums, nums.length, nums, nums.length-k, nums.length-k);
        copy(nums, k, tmp, k, k);
    }

    public void copy(int[] dest, int dest_idx, int[] src, int src_idx, int k) {
        for (int i = k; i > 0; i--) {
            dest[--dest_idx] = src[--src_idx];
        }
    }

    public static void main(String[] args) {
        int[] nums = new int[]{1};
        new Rotate().rotate(nums, 1);
        System.out.println(Arrays.toString(nums));
    }


    public void rotate2(int[] nums, int k) {
        k %= nums.length;
        reverse(nums, 0, nums.length);
        reverse(nums, 0, k);
        reverse(nums, k, nums.length);
    }

    public void reverse(int[] nums, int low, int high) {
        int len = high - low;
        for (int i = 0; i < len / 2; i++) {
            int tmp = nums[low + i];
            nums[low + i] = nums[high - i - 1];
            nums[high - i - 1] = tmp;
        }
    }
}
