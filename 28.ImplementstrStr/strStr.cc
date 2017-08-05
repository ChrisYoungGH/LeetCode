#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack == "" && needle == "") {
            return 0;
        }

        for (int i = 0; i < int(haystack.size()) - int(needle.size()) + 1; i++) {
            cout << i << endl;
            if (haystack.substr(i, needle.size()) == needle) {
                return i;
            }
        }

        return -1;
    }
};

int main(int argc, char const *argv[]) {
    string haystack = "abb";
    string needle = "abaaa";
    Solution s = Solution();
    cout << s.strStr(haystack, needle) << endl;
    return 0;
}
