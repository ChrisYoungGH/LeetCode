#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

void backtrack(vector<string> &res, string s, int open, int close, int max) {
	if (s.length() == max * 2) {
		res.push_back(s);
		return;
	}

	if (open < max) {
		backtrack(res, s + "(", open + 1, close, max);
	}
	if (close < open) {
		backtrack(res, s + ")", open, close + 1, max);
	}
}

vector<string> generateParenthesis(int n) {
	vector<string> res;
	backtrack(res, "", 0, 0, n);
	return res;
}

int main() {
	vector<string> res = generateParenthesis(4);
	for (int i = 0; i < res.size(); i++) {
		printf("%s\n", res[i].c_str());
	}
	return 0;
}