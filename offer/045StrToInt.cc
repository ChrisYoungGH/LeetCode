#include <iostream>
#include <string>
#include <climits>

using namespace std;

int global_status = true;

class Solution {
public:
    int StrToInt(string str) {
  		int n = str.length();

  		if (!n) {
  			global_status = false;
  			return 0;
  		}

  		int validStart = n, validEnd = 0;
  		for (int i = 0; i < n; i++) {
  			if (str[i] != ' ') {
  				validStart = i;
  				break;
  			}
  		}
  		for (int i = n-1; i >= 0; i--) {
  			if (str[i] != ' ') {
  				validEnd = i;
  				break;
  			}
  		}
  		if (validStart > validEnd) {
  			global_status = false;
  			return 0;
  		}

  		for (int i = validStart; i <= validEnd; i++) {
  			if ((str[i] > '0' && str[i] < '9') || (i == validStart && (str[i] == '+' || str[i] == '-'))) {
  				continue;
  			}
  			global_status = false;
  			return 0;
  		}

  		int flag = 1;
  		if (str[validStart] == '+') {
  			flag = 1;
  			validStart++;
  		}
  		else if (str[validStart] == '-') {
  			flag = -1;
  			validStart++;
  		}
  		if (validStart > validEnd) {
  			global_status = false;
  			return 0;
  		}

  		long res = 0;
  		for (int i = validStart; i <= validEnd; i++) {
  			res = res * 10 + (str[i] - '0');
  		}
  		res *= flag;

  		if (res > long(INT_MAX) || res < long(INT_MIN)) {
  			global_status = false;
  			return 0;
  		}

  		return int(res);
    }
};

int main() {
	Solution s = Solution();
	string str = "+";
	int res = s.StrToInt(str);
	if (global_status) {
		cout << res << endl;
	}
	else {
		cout << "wrong" << endl;
	}
}