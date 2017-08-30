class Solution {
public:
    int countSegments(string s) {
        int count = 0;
        int flag = 0;
        for (char c : s) {
            if (!isspace(c)) {
                flag = 1;
            }
            else {
                if (flag == 1) {
                    count++;
                }
                flag = 0;
            }
        }
        return count + flag;
    }
};
