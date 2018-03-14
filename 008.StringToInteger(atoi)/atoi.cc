#include <iostream>
#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int len = str.length();

        // 1. 判断是否为空
        if (len == 0) {
            return 0;
        }

        // 2. 去除前面多余的空格
        int left = 0;
        while (left < len && str[left] == ' ') {
            left++;
        }
        if (left == len) {
            return 0;
        }

        // 3. 取出可能的符号位
        char flag = '+';
        if (str[left] == '+' || str[left] == '-') {
            flag = str[left++];
        }

        // 4. 取出满足数字的部分
        int right = left;
        while (right < len && str[right] >= '0' && str[right] <= '9') {
            right++;
        }
        if (right == left) {
            return 0;
        }

        // 5. 根据长度判断是否溢出
        if (right - left > 10) {
            return flag == '-' ? INT_MIN : INT_MAX;
        }

        // 6. 转换
        long ans = 0;
        for (int i = left; i < right; i++) {
            ans = ans * long(10) + long(str[i] - '0');
        }

        // 7. 加上符号位
        ans = flag == '-' ? -ans : ans;

        // 8. 判断是否溢出
        ans = min(ans, long(INT_MAX));
        ans = max(ans, long(INT_MIN));

        return int(ans);
    }
};


int main(int argc, char const *argv[]) {
    Solution sl = Solution();
    string s = "-23NNb";
    cout << sl.myAtoi(s) << endl;
    return 0;
}
