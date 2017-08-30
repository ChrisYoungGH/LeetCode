class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0, left = 0, right = 0;
        for (int i = 0; i < int(s.length()); i++) {
            bool repeat = false;
            int j = left;
            while (j < i) {
                if (s[i] == s[j]) {
                    repeat = true;
                    break;
                }
                j++;
            }

            if (repeat) {
                maxlen = max(maxlen, right - left);
                left = j + 1;
            }

            right++;
        }

        return max(maxlen, right - left);
    }
};
