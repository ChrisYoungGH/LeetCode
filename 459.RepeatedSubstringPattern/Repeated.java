class Solution {
    public boolean repeatedSubstringPattern(String s) {
        int end = 1;

        while (true) {
            if (end >= s.length()) {
                return false;
            }

            String pattern = s.substring(0, end);
            int sublength = pattern.length();

            if (s.length() % sublength != 0) {
                end++;
                continue;
            }

            boolean flag = true;
            for (int i = end; i < s.length(); i += sublength) {
                if (!s.substring(i, i+sublength).equals(pattern)) {
                    flag = false;
                    end++;
                    break;
                }
            }

            if (flag == true) {
                return true;
            }
        }
    }

    public boolean repeatedSubstringPatternOpt(String s) {
        if (s == null) {
            return false;
        }

        String ss = (s + s)；
        return ss.substring(1, ss.length()-1).indexOf(s) != -1;
    }
}
