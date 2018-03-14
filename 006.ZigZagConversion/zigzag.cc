#include <string>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        string zigzag[numRows];

        int row = 0;
        bool down = true;
        for (char c : s) {
            zigzag[row] += c;

            // 判断方向
            if (down && row + 1 == numRows) {
                down = false;
            }
            if (!down && row - 1 < 0) {
                down = true;
            }

            // 判断是否增减行号
            if (down && row + 1 < numRows) {
                row++;
            }
            if (!down && row - 1 >= 0) {
                row--;
            }
        }

        string ans;
        for (string sb : zigzag) {
            ans += sb;
        }

        return ans;
    }
};

int main(int argc, char const *argv[]) {
    Solution sl = Solution();
    string s = "AB";
    cout << sl.convert(s, 1);
    return 0;
}
