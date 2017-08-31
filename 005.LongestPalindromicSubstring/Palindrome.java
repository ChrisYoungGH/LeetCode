class Solution {
    public String longestPalindrome(String s) {
        int maxLen = 1;
        String longestPs = s.substring(0, 1);

        for (int i = 0; i < s.length(); i++) {
            String psOdd = extendPalindrome(s, i, i);
            String psEven = extendPalindrome(s, i, i+1);
            String ps = psOdd.length() > psEven.length() ? psOdd : psEven;
            if (ps.length() > maxLen) {
                maxLen = ps.length();
                longestPs = ps;
            }
        }

        return longestPs;
    }

    public String extendPalindrome(String s, int i, int j) {
        while (i >= 0 && j < s.length() && s.charAt(i) == s.charAt(j)) {
            i--; j++;
        }
        return s.substring(i+1, j);
    }
}
