class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> count;
        for (char c : s) {
            count[c]++;
        }
        int sum = 0, odd = 0;
        for (map<char,int>::iterator it = count.begin(); it != count.end(); ++it) {
            int v = it->second;
            sum += v;
            if (v % 2) {
                odd++;
            }
        }

        return sum - odd + min(odd, 1);
    }
};
