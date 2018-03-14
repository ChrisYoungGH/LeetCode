public class Solution {
    public int maximumProduct(int[] nums) {
        int max1, max2, max3, min1, min2;
        max1 = max2 = max3 = -1001;
        min1 = min2 = 1001;

        for (int n : nums) {
            if (n > max1) {
                max3 = max2; max2 = max1; max1 = n;
            }
            else if (n > max2) {
                max3 = max2; max2 = n;
            }
            else if (n > max3) {
                max3 = n;
            }

            if (n < min1) {
                min2 = min1; min1 = n;
            }
            else if (n < min2) {
                min2 = n;
            }
        }

        return Math.max(min1*min2, max2*max3) * max1;
    }
}
