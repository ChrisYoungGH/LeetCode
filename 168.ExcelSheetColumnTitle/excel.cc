#include <string>
using namespace std;
class Solution {
public:
    string convertToTitle(int n) {
        string ans = "";
        while (n > 0) {
            n -= 1;
            ans = char((n % 26) + 'A') + ans;
            n /= 26;
        }
        return ans;
    }
};
