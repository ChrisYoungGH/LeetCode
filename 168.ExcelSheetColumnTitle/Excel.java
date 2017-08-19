class Solution {
    public String convertToTitle(int n) {
        String ans = "";
        while (n > 0) {
            n -= 1;
            ans = String.valueOf((char)(n % 26 + 'A')) + ans;
            n /= 26;
        }

        return ans;
    }
}
