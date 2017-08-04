
public class Reverse {

    // 方法1：每次判断是否在最大值和最小值内，不是则返回0
    // 对于有很多不合格输入样例，反而更快
    // 要用long
    public int reverse(int x) {
        if (x == 0) {
            return 0;
        }

        // final int MAX_INT = 2147483647;
        // final int MIN_INT = -MAX_INT;
        final int MAX_INT = Integer.MAX_VALUE;
        final int MIN_INT = Integer.MIN_VALUE;

        long res = 0;
        while (x != 0) {
            res = res * 10 + x % 10;
            x /= 10;
            if (res > MAX_INT || res < MIN_INT) {
                return 0;
            }
        }

        return (int)res;
    }

    // 方法2：判断最高位符号是否相同，仍然要用long
    public int reverse2(int x) {
        if (x == 0) {
            return 0;
        }

        int sign = x >> 31;

        long res = 0;
        while (x != 0) {
            res = res * 10 + x % 10;
            x /= 10;
        }

        if (res >> 31 == sign) {
            return (int)res;
        }
        return 0;
    }

    // 方法3：转化为字符串，再反序输出
    public int reverse3(int x) {
        if (x == 0) {
            return 0;
        }

        String xStr = String.valueOf(x);
        StringBuilder sb = new StringBuilder();
        int flag = 0;
        if (x < 0) {
            sb.append("-");
            flag = 1;
        }
        for (int i = xStr.length() - 1; i >= flag; i--) {
            sb.append(xStr.charAt(i));
        }

        long res = Long.parseLong(sb.toString());

        if (res >> 31 == x >> 31) {
            return (int)res;
        }
        return 0;
    }


    public static void main(String[] args) {
        int x = -2147483647;
        int result = new Reverse().reverse3(x);
        System.out.println(result);
    }
}
