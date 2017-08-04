#include <iostream>
#include <cstdio>
#include <climits>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
public:

    // 方法1：直接反序，每次判断界
    int reverse(int x) {
        if (x == 0) {
            return 0;
        }

        const int MAX_INT = 2147483647;
        const int MIN_INT = -MAX_INT;

        long res = 0;
        while (x != 0) {
            res = res * 10 + x % 10;

            if (res > MAX_INT || res < MIN_INT) {
                return 0;
            }

            x /= 10;
        }

        return int(res);
    }

    // 方法2：输出到字符串，反序后输入，最后判断界
    int reverse2(int x) {
        if (x == 0) {
            return 0;
        }

        int sign = x >> 31;

        int flag = 1;
        if (x < 0) {
            flag = -1;
            x = -x;
        }

        char xStr[1024];
        sprintf(xStr, "%d", x);
        int len = strlen(xStr);
        for (int i = 0; i < len / 2; i++) {
            char temp = xStr[i];
            xStr[i] = xStr[len-i-1];
            xStr[len-i-1] = temp;
        }

        long res;
        sscanf(xStr, "%ld", &res);
        res *= flag;

        if (res >> 31 == sign) {
            return int(res);
        }

        return 0;
    }


    // 方法3：同2，但使用字符串流，更简洁
    int reverse3(int x) {
        long long y = x;
        string s;
        stringstream stream;

        stream << x;
        stream >> s;
        std::reverse(s.begin(), s.end());
        stream.clear();

        stream << s;
        stream >> y;

        if (abs(y) > pow(2, 31) - 1) {
            return 0;
        }

        return x > 0 ? y : -y;
    }
};


int main() {
    Solution s = Solution();
    int x = -1234;
    cout << s.reverse3(x) << endl;
    return 0;
}
