#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<string> Permutation(string str) {
		vector<string> res;
		if (str.length() == 0) {
			return res;
		}

		Permutation(str, res, 0);
		sort(res.begin(), res.end());

		return res;
	}

	void Permutation(string str, vector<string> &res, int begin) {
		if (begin == str.length()) {
			res.push_back(str);
			return;
		}

		for (int i = begin; i < str.length(); i++) {
			if (i == begin || str[i] != str[begin]) {
				swap(str[i], str[begin]);
				Permutation(str, res, begin + 1);
				swap(str[i], str[begin]);
			}
		}
	}
};

int main() {
	string str = "abc";
	Solution s = Solution();
	vector<string> res = s.Permutation(str);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}
}