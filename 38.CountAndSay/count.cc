#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n < 1) {
            return "";
        }

        string curr = "1";
        for (int i = 0; i < n - 1; i++) {
            curr = read(curr);
        }

        return curr;
    }

    string read(string str) {
        if (str.size() == 0) {
            return "";
        }

        char digit = str[0];
        int count = 1;
        string res = "";
        for (int i = 1; i < int(str.size()); i++) {
            if (str[i] == digit) {
                count++;
            }
            else {
                res.push_back(char(count+'0'));
                res.push_back(digit);
                digit = str[i];
                count = 1;
            }
        }
        res.push_back(char(count+'0'));
        res.push_back(digit);

        return res;
    }
};

int main(int argc, char const *argv[]) {
    Solution s = Solution();
    cout << s.countAndSay(4) << endl;
    return 0;
}
