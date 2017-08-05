#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }

        if (strs.size() == 1) {
            return strs[0];
        }

        unsigned int minLen = strs[0].size();
        for (unsigned int i = 1; i < strs.size(); i++) {
            minLen = strs[i].size() < minLen ? strs[i].size() : minLen;
        }

        string repStr = strs[0];
        int longestIndex = 0;
        bool flag = true;

        for (unsigned int i = 0; i < repStr.size(); i++) {
            char c = repStr[i];
            for (unsigned int j = 1; j < strs.size(); j++) {
                if (strs[j][i] != c) {
                    flag = false;
                    break;
                }
            }
            if (!flag) {
                break;
            }
            longestIndex++;
        }

        repStr[longestIndex] = '\0';
        return longestIndex > 0 ? repStr : "";
    }

};

int main() {
    string strsArr[] = {"hello", "hella", "helly", "helllllllllll"};
    vector<string> strs(strsArr, strsArr + 4);
    Solution s = Solution();
    string res = s.longestCommonPrefix(strs);
    cout << res << endl;
}
