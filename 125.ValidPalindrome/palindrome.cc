#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string str = "qwertyuiopasdfghjklzxcvbnm0123456789";
        set<char> alphebet;
        for (char c : str) {
            alphebet.insert(c);
        }

        vector<char> s_filter;
        for (char c : s) {
            c = tolower(c);
            if (alphebet.find(c) != alphebet.end()) {
                s_filter.push_back(c);
            }
        }

        for (int i = 0; i < int(s_filter.size()); i++) {
            if (s_filter[i] != s_filter[s_filter.size()-i-1]) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution sl = Solution();
    string s = "A man, a plan, a canal: Panama";
    cout << sl.isPalindrome(s);
    return 0;
}
