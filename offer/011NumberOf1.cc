class Solution {
public:
    int NumberOf1(int n) {
        int cnt = 0;
        unsigned int flag = 1;
        while (flag) {
            cnt += ((n & flag) > 0);
            flag <<= 1;
        }
        
        return cnt;
    }

    int NumberOf1_2(int n) {
        int cnt = 0;
        while (n) {
            n = n & (n-1);
            cnt++;
        }
        return cnt;
    }
};