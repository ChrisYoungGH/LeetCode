class Solution {
public:
    string reverseStr(string s, int k) {
        int end = s.length() / (2*k) * (2*k);
        for (int i = 0; i < end; i += 2*k) {
            reverse(s, i, i+k);
        }
        return reverse(s, end, int(s.length()) - end > k ? end + k : int(s.length()));
    }

    string reverse(string& s, int begin, int end) {
        for (int i = begin; i < (end - begin) / 2 + begin; i++) {
            char tmp = s[i];
            s[i] = s[end - (i - begin) - 1];
            s[end - (i - begin) - 1] = tmp;
        }
        return s;
    }
};
