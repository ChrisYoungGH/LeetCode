#include <iostream>
#include <string>

using namespace std;

bool isMatch(string s, string p) {
	if (p.empty()) {
		return s.empty();
	}

	if (p[1] == '*') {
		return (isMatch(s, p.substr(2)) || 
			(!s.empty() && (p[0] == s[0] || p[0] == '.') && isMatch(s.substr(1), p)));
	}

	return !s.empty() && (p[0] == s[0] || p[0] == '.') &&
		isMatch(s.substr(1), p.substr(1));
}

bool isMatch2(string s, string p) {
	int m = s.size(), n = p.size();

	bool f[m+1][n+1];

	f[0][0] = true;
	for (int i = 1; i <= m; i++) {
		f[i][0] = false;
	}
	for (int j = 1; j <= n; j++) {
		f[0][j] = j > 1 && p[j-1] == '*' && f[0][j-2];
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (p[j-1] != '*') {
				f[i][j] = f[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
			}
			else {
				f[i][j] = f[i][j-2] || (s[i-1] == p[j-2] || p[j-2] == '.') && f[i-1][j];
			}
		}
	}

	return f[m][n];
}

int main() {
	string s = "aab", p = "c*a*b";
	cout << isMatch2(s, p) << endl;
	return 0;
}