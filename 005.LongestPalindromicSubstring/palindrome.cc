#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int low = 0, maxLen = 1;

        for (int i = 0; i < int(s.length()); i++) {
            extendPalindrome(s, i, i, low, maxLen);
            extendPalindrome(s, i, i+1, low, maxLen);
        }

        return s.substr(low, maxLen);
    }

    void extendPalindrome(string s, int i, int j, int &low, int &maxLen) {
        while (i >= 0 && j < int(s.length()) && s[i] == s[j]) {
            i--; j++;
        }
        if (j - i - 1 > maxLen) {
            maxLen = j - i - 1;
            low = i + 1;
        }
    }
};

int main(int argc, char const *argv[]) {
    Solution sl = Solution();
    string s = "xyzabcbaqqq";
    cout << sl.longestPalindrome(s) << endl;
    return 0;
}
