#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = int(s.size()) - 1;
        while (i >= 0) {
            if (s[i] != ' ') {
                break;
            }
            i--;
        }

        int count = 0;
        while (i >= 0 && s[i] != ' ') {
            count++;
            i--;
        }

        return count;
    }
};

int main(int argc, char const *argv[]) {
    Solution s = Solution();
    cout << s.lengthOfLastWord("   ") << endl;
    return 0;
}
