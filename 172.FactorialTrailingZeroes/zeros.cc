class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        long m = 5;
        while (m <= n) {
        	ans += n / m;
        	m *= 5;
        }
        return ans;
    }
};