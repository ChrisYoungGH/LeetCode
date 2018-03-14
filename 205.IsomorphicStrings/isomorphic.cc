class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int* ds = string2Digit(s);
        int* dt = string2Digit(t);

        for (int i = 0; i < s.length(); i++) {
            if (ds[i] != dt[i]) {
                return false;
            }
        }
        return true;
    }

    int* string2Digit(string str) {
        int* ds = new int[str.length()];
        int count = 0;
        map<char, int> index;
        for (int i = 0; i < str.length(); i++) {
            char c = str[i];
            map<char, int>::iterator it = index.find(c);
            if (it == index.end()) {
                index[c] = count++;
            }
            ds[i] = index[c];
        }
        return ds;
    }

    bool isIsomorphic(string s, string t) {
        int m1[256] = {0}, m2[256] = {0};
        for (int i = 0; i < s.length(); i++) {
            if (m1[s[i]] != m2[t[i]]) {
                return false;
            }
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
        return true;
    }
};
