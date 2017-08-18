class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char, int> indexP;
        map<string, int> indexS;
        int i = 0, n = pattern.size();
        stringstream in(str);
        for (string word; in >> word; i++) {
            if (indexP[pattern[i]] != indexS[word]) {
                return false;
            }
            indexP[pattern[i]] = indexS[word] = i+1;
        }
        return i == n;
    }
};
