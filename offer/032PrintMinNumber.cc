#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	string PrintMinNumber(vector<int> &nums) {
		string res;

		int n = nums.size();
		if (!n) {
			return res;
		}

		vector<string> strNums(n);
		for (int i = 0; i < n; i++) {
			stringstream ss;
			ss << nums[i];
			ss >> strNums[i];
		}

		sort(strNums.begin(), strNums.end(), cmp);

		stringstream ss;
		for (int i = 0; i < n; i++) {
			ss << strNums[i];
		}
		ss >> res;

		return res;
	}

	static int cmp(string s1, string s2) {
		return s1 + s2 < s2 + s1;
	}
};


int main() {
	Solution s = Solution();
	vector<int> nums = {3, 32, 321};
	cout << s.PrintMinNumber(nums) << endl;
	return 0;
}