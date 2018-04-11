#include <iostream>
#include <cstring>

using namespace std;

class Solution {
public:
    bool isNumeric(char* str) {
    	if (!str) {
    		return false;
    	}

    	int len = strlen(str);
    	if (!len) {
    		return false;
    	}

    	bool dotFlag = false, expFlag = false;

    	for (int i = 0; i < len; i++) {
    		if (str[i] < '0' || str[i] > '9') {
    			if (i != 0) {
    				if (str[i] == '.') {
    					if (dotFlag || expFlag || i == len-1) {
    						return false;
    					}
    					dotFlag = true;
    				}
    				else if (str[i] == 'e' || str[i] == 'E') {
    					if (expFlag || i == len-1) {
    						return false;
    					}
    					expFlag = true;
    				}
    				else {
    					if ((str[i] == '-' || str[i] == '+') && (str[i-1] == 'e' || str[i-1] == 'E')) {
    						continue;
    					}
    					return false;
    				}
    			}

    			else {
    				if (len == 1 || (str[i] != '+' && str[i] != '-')) {
    					return false;
    				}
    			}
    		}
    	}


    	return true;
    }

};

int main() {
	Solution s = Solution();
	char strs[11][100] = {"+100","5e2","-123","3.1416","-1E-16","12e","1a3.14","1.2.3","+-5","12e+4.3", "123.45e+6"};
	for (int i = 0; i < 11; i++) {
		cout << strs[i] << ": " << s.isNumeric(strs[i]) << endl;
	}
}
