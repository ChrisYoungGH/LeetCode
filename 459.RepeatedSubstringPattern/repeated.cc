class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int end = 1;

        while (true) {
            if (end >= s.length()) {
                return false;
            }

            string pattern = s.substr(0, end);
            int sublen = pattern.length();

            if (s.length() % sublen) {
                end++;
                continue;
            }

            bool flag = true;
            for (int i = end; i < s.length(); i += sublen) {
                if (s.substr(i, end) != pattern) {
                    flag = false;
                    end++;
                    break;
                }
            }

            if (flag) {
                return true;
            }
        }
    }

    bool repeatedSubstringPattern(string s) {
        if (s.length() == 0) {
            return false;
        }
        string s1 = s + s;
        string s2 = s1.substr(1, int(s1.length())-1);
        return s2.find(s) != string::npos;
    }
};
