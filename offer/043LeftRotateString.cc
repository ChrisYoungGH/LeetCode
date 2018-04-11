#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string LeftRotateString(string str, int n) {
    	int len = str.length();

        if (!len || n < 0)  {
        	return str;
        }
        n %= len;

        return str.substr(n, len-n) + str.substr(0, n);
    }

    string LeftRotateString2(string str, int n) {
    	int len = str.length();
    	if (!len || n < 0) {
    		return str;
    	}
    	n %= len;

    	reverse(str, 0, len);
    	reverse(str, 0, len-n);
    	reverse(str, len-n, len);

    	return str;
    }

    void reverse(string &str, int low, int high) {
    	for (int i = low; i < (low + high) / 2; i++) {
    		swap(str[i], str[high-(i-low)-1]);
    	}
    }
};

int main() {
	Solution s = Solution();
	string str = "abcXYZdef";
	cout << s.LeftRotateString2(str, 3) << endl;
	return 0;

}