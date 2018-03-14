class Solution {
    public int lengthOfLongestSubstring(String s) {
        int maxlen = 0, left = 0, right = 0;
        for (int i = 0; i < s.length(); i++) {
            boolean repeat = false;
            int j = left;
            while (j < i) {
                if (s.charAt(i) == s.charAt(j)) {
                    repeat = true;
                    break;
                }
                j++;
            }

            if (repeat == true) {
                maxlen = Math.max(maxlen, right - left);
                left = j + 1;
            }

            right++;
        }

        return Math.max(maxlen, right - left);
    }
}
