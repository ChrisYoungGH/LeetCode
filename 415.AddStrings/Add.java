class Solution {
    public String addStrings(String num1, String num2) {
        int p1 = num1.length() - 1, p2 = num2.length() - 1;
        int up = 0;
        StringBuilder ans = new StringBuilder();
        while (p1 >= 0 || p2 >= 0) {
            int v1 = 0, v2 = 0;
            if (p1 >= 0) {
                v1 = num1.charAt(p1) - '0';
                p1--;
            }
            if (p2 >= 0) {
                v2 = num2.charAt(p2) - '0';
                p2--;
            }
            int sum = v1 + v2 + up;
            up = sum / 10;
            ans.append(sum % 10);
        }
        if (up > 0) {
            ans.append(up);
        }
        return ans.reverse().toString();
    }
}
