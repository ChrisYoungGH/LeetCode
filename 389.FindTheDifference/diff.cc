class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char,int> letters;
        for (char c : s) {
            letters[c]++;
        }

        for (char c : t) {
            if (!letters[c]) {
                return c;
            }
            letters[c]--;
        }

        return 0;
    }
};
