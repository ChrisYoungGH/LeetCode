#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string ReverseSentence(string str) {
        int n = str.length();
        if (!n) {
        	return str;
        }

        reverse(str, 0, n);

        int start = 0, end = 1;
        while (end < n) {
        	while (end < n && str[end] != ' ') end++;
        	reverse(str, start, end);
        	start = end + 1;
        	end = start + 1;
        }

        return str;
    }

    void reverse(string &str, int low, int high) {
    	for (int i = low; i < (low + high) / 2; i++) {
    		swap(str[i], str[high - (i-low) - 1]);
    	}
    }
};

int main() {
	Solution s = Solution();
	string str = "student. a am I";
	cout << s.ReverseSentence(str) << endl;
	return 0;
}