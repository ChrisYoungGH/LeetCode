public class Climb {
    // 直接法：由于溢出，只适合小的数(计算组合数时乘法会溢出)
    public int climbStairs(int n) {
        if (n == 0) {
            return 0;
        }
        int count = 0;
        for (int i = 0; i <= n / 2; i++) {
            count += combination(n-i, i);
        }
        return count;
    }

    public int combination(int n, int k) {
        if (k > n / 2) {
            k = n - k;
        }
        long ans = 1;
        for (int i = n; i > n-k; i--) {
            ans *= i;
        }
        for (int i = 1; i <= k; i++) {
            ans /= i;
        }
        return (int)ans;
    }

    // 斐波那契数列
    public int climbStairs2(int n) {
        if (n <= 0) {
            return 0;
        }
        int f1 = 1, f2 = 1;
        for (int i = 0; i < n; i++) {
            f1 = (f2 += f1) - f1;
            // 也就是：
            // int temp = f1;
            // f1 = f2;
            // f2 += temp;
        }
        return f1;
    }

    public static void main(String[] args) {
        Climb c = new Climb();
        // for (int i = 1; i < 10; i++) {
        int i = 12;
            System.out.println(i + ":" + c.climbStairs(i));
            System.out.println(i + ":" + c.climbStairs2(i));
        // }
        // System.out.println(c.combination(7,2));
    }
}
