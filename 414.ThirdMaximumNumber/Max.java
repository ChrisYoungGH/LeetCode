public class Max {
    public int thirdMax(int[] nums) {
        long max1 = Long.MIN_VALUE, max2 = Long.MIN_VALUE, max3 = Long.MIN_VALUE;
        for (int n : nums) {
            if (n > max1) {
                max3 = max2;
                max2 = max1;
                max1 = n;
            }
            else if (n == max1) {
                continue;
            }
            else if (n > max2) {
                max3 = max2;
                max2 = n;
            }
            else if (n == max2) {
                continue;
            }
            else if (n > max3) {
                max3 = n;
            }
        }

        if (max3 > Long.MIN_VALUE) {
            return (int)max3;
        }
        return (int)max1;
    }

    public static void main(String[] args) {
        int nums[] = {-2147483648,1,1};
        System.out.println(new Max().thirdMax(nums));
    }

}
