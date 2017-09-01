class Solution {
public:
    int findLUSlength(string a, string b) {
        if (a.length() != b.length()) {
            return max(a.length(), b.length());
        }

        if (a != b) {
            return a.length();
        }

        return -1;
    }
};
