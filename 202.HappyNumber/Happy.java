public class Solution {
    public boolean isHappy(int n) {
        Set<Integer> nums = new HashSet<>();

        while (n > 1) {
            if (nums.contains(n)) {
                return false;
            }
            nums.add(n);

            int tmp = n;
            int sum = 0;
            while (tmp > 0) {
                int d = tmp % 10;
                tmp /= 10;
                sum += d * d;
            }

            n = sum;
        }

        return true;
    }
}
