import java.util.regex.*;
class Atoi {
    public int myAtoi(String str) {
        // 1. 是否为空
        if (str == null) {
            return 0;
        }

        // 2. 去除多余空格
        str = str.trim();

        // 3. 是否符合格式，即以整数形式开头
        Pattern p = Pattern.compile("^[+-]?[0-9]+");
        Matcher m = p.matcher(str);
        if (m.find()) {
            str = m.group();
        }
        else {
            return 0;
        }

        // 4. 判断是否有符号位
        int left = str.charAt(0) == '+' || str.charAt(0) == '-' ? 1 : 0;

        // 5. 判断长度
        if (str.length() - left > 10) {
            return str.charAt(0) == '-' ? Integer.MIN_VALUE : Integer.MAX_VALUE;
        }

        // 6. 转换
        long ans = 0;
        for (int i = left; i < str.length(); i++) {
            ans = ans * (long)10 + (long)(str.charAt(i) - '0');
        }

        // 7. 加上符号位
        if (str.charAt(0) == '-') {
            ans = -ans;
        }

        // 8.判断是否溢出
        System.out.println(ans);
        ans = Math.min(ans, Integer.MAX_VALUE);
        System.out.println(ans);
        ans = Math.max(ans, Integer.MIN_VALUE);
        System.out.println(ans);

        return (int)ans;

    }

    public static void main(String[] args) {
        String str = "9223372036854775809";
        System.out.println(new Atoi().myAtoi(str));
    }
}
