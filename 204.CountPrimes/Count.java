public class Solution {
    public int countPrimes(int n) {
        if (n < 3) {
            return 0;
        }

        int[] prime = new int[n];
        prime[0] = prime[1] = 1;

        for (int i = 2; i < (int)(Math.sqrt(n))+1; i++) {
            if (prime[i] == 0) {
                for (int j = i*i; j < n; j += i) {
                    prime[j] = 1;
                }
            }
        }

        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (prime[i] == 0) {
                sum++;
            }
        }

        return sum;
    }
}
