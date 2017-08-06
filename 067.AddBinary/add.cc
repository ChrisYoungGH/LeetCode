#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int ia = a.size()-1, ib = b.size()-1;
        int carry = 0;
        string res = "";
        while (ia >= 0 || ib >= 0 || carry >0) {
            int va = 0, vb = 0;
            if (ia >= 0) {
                va = a[ia--] - '0';
            }
            if (ib >= 0) {
                vb = b[ib--] - '0';
            }
            int sum = va + vb + carry;

            res.push_back(char(sum % 2 + '0'));
            carry = sum / 2;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

int main(int argc, char const *argv[]) {
    Solution s = Solution();
    cout << s.addBinary("11", "1") << endl;
    return 0;
}
