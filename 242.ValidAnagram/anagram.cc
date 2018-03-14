class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        map<char, int> chars;
        for (int i = 0; i < s.length(); i++) {
            if (chars.find(s[i]) == chars.end()) {
                chars[s[i]] = 0;
            }
            chars[s[i]]++;
        }

        for (int i = 0; i < t.length(); i++) {
            if (chars.find(t[i]) == chars.end() || chars[t[i]] == 0) {
                return false;
            }
            chars[t[i]]--;
        }

        return true;
    }
};
