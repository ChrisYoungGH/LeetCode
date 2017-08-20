class Solution {
    public int findNthDigit(int n) {
        int k = 0, base = 0;
        while (true) {
            long tmp = 9 * k * (long)Math.pow(10, k-1);
            if (tmp > (long)n) {
                break;
            }
            base += tmp;
            k++;
        }

        int remain = n - base;
        int num = (int)Math.pow(10, k-1) - 1 + (remain / k + (remain % k > 0 ? 1 : 0));
        int nDigit = (k - remain % k) % k;

        int ans = 0;
        for (int i = 0; i < nDigit + 1; i++) {
            ans = num % 10;
            num /= 10;
        }

        return ans;
    }

    public static void main(String[] args) {
        System.out.println(new Solution().findNthDigit(1000000000));
    }
}
