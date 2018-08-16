#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<int> line(n);
        vector<vector<int> > ans(n, line);

        if (!n) {
        	return ans;
        }

        int v = 1;
        int l = 0, r = n-1, t = 0, b = n-1;
        while (l <= r && t <= b) {
        	for (int j = l; j <= r; j++) {
        		ans[t][j] = v++;
        	}
        	t++;

        	for (int i = t; i <= b; i++) {
        		ans[i][r] = v++;
        	}
        	r--;

        	for (int j = r; j >= l; j--) {
        		ans[b][j] = v++;
        	}
        	b--;

        	for (int i = b; i >= t; i--) {
        		ans[i][l] = v++;
        	}
        	l++;
        }

        return ans;
    }
};

int main() {
	int n = 3;
	Solution s = Solution();
	vector<vector<int> > ans = s.generateMatrix(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}