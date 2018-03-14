class Solution {
    public boolean isPalindrome(String s) {
        if (s == null) {
            return true;
        }

        s = s.toLowerCase();
        StringBuffer sb = new StringBuffer();
        for (char c : s.toCharArray()) {
            if ((c>='a' && c<='z') || (c>='0' && c<='9')) {
                sb.append(c);
            }
        }
        String s_filter = sb.toString();
        for (int i = 0; i < s_filter.length(); i++) {
            if (s_filter.charAt(i) != s_filter.charAt(s_filter.length()-i-1)) {
                return false;
            }
        }

        return true;
    }
}
