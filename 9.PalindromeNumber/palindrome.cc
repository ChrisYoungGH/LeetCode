#include <iostream>
#include <stream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        stringstream stream;
        string s;
        stream << x;
        stream >> s;
        for (int i = 0; i < s.size() / 2; i++) {
            if (s[i] != s[s.size() - i - 1]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    int x = 123321;
    Solution s = Solution();
    cout << s.isPalindrome(x) << endl;
}
