import java.util.*;

public class Sum {
    public int[] twoSum(int[] numbers, int target) {
        if (numbers == null || numbers.length == 0) {
            return new int[2];
        }

        int head = 0, tail = numbers.length - 1;
        while (head < tail) {
            int sum = numbers[head] + numbers[tail];
            if (sum == target) {
                return new int[] {head+1, tail+1};
            }
            if (sum < target) {
                head++;
            }
            else {
                tail--;
            }
        }

        return new int[2];
    }

    public static void main(String[] args) {
        System.out.println(Arrays.toString(new Sum().twoSum(new int[]{2,7,11,15}, 9)));
    }
}
