class Solution {
public:
    string addStrings(string num1, string num2) {
        int p1 = num1.length() - 1, p2 = num2.length() - 1;
        int up = 0;
        string ans = "";
        while (p1 >= 0 || p2 >= 0) {
            int v1 = p1 >= 0 ? num1[p1--] - '0' : 0;
            int v2 = p2 >= 0 ? num2[p2--] - '0' : 0;
            int sum = v1 + v2 + up;
            up = sum / 10;
            ans = char(sum % 10 + '0') + ans;
        }
        return up > 0 ? char(up + '0') + ans : ans;
    }
};
