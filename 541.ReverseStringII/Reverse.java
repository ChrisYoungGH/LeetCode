class Solution {
    public String reverseStr(String s, int k) {
        if (s == null) {
            return null;
        }

        int end = s.length() / (2*k) * (2*k);

        StringBuffer sb = new StringBuffer();
        for (int i = 0; i < end; i += 2*k) {
            sb.append(reverse(s.substring(i, i+k))).append(s.substring(i+k, i+2*k));
        }

        int begin = end;
        end = s.length() - begin > k ? begin + k : s.length();

        sb.append(reverse(s.substring(begin, end)));

        if (end < s.length()) {
            sb.append(s.substring(end, s.length()));
        }

        return sb.toString();
    }

    public String reverse(String s) {
        char[] s_char = s.toCharArray();
        StringBuffer sb = new StringBuffer();
        for (int i = s_char.length-1; i >= 0; i--) {
            sb.append(s_char[i]);
        }
        return sb.toString();
    }
}
