#include <iostream>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int begin = 0;
        for (int i = 0; i < int(s.length()); i++) {
            if (s[i] == ' ') {
                reverse(s, begin, i);
                begin = i + 1;
            }
        }
        reverse(s, begin, s.length());
        return s;
    }

    void reverse(string &s, int begin, int end) {
        int length = end - begin;
        for (int i = begin; i < begin + length / 2; i++) {
            char tmp = s[i];
            int index = end - (i - begin) - 1;
            s[i] = s[index];
            s[index] = tmp;
        }
    }
};

int main(int argc, char const *argv[]) {
    string s = "Let's  take  LeetCode contest  ";
    Solution sl = Solution();
    cout << sl.reverseWords(s) << endl;
    return 0;
}
