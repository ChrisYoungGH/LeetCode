#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
    	int len = s.length();
    	if (!len) {
    		return true;
    	}

        int i = 0, j = s.length() - 1;
        while (i < j) {
        	while (i < j && !isalnum(s[i])) i++;
        	while (j > i && !isalnum(s[j])) j--;
        	if (i == j) {
        		break;
        	}

        	char si = tolower(s[i]);
        	char sj = tolower(s[j]);
        	if (si != sj) {
        		return false;
        	}

        	i++; j--;
        }

        return true;
    }
};

int main() {
	string str = "1a2";
	Solution s = Solution();
	cout << s.isPalindrome(str) << endl;
	return 0;
}