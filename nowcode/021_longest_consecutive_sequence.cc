#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, int> m;
        int res = 0;
        for (int n : num) {
        	if (m.find(n) == m.end()) {
        		int left = m.find(n-1) != m.end() ? m[n-1] : 0;
        		int right = m.find(n+1) != m.end() ? m[n+1] : 0;

        		int sum = left + right + 1;
        		res = sum > res ? sum : res;

        		m[n] = sum;
        		m[n-left] = sum;
        		m[n+right] = sum;
        	}
        }

        return res;
    }
};

int main() {
	vector<int> vec = {100,4,200,1,3,2};

	Solution s = Solution();
	cout << s.longestConsecutive(vec) << endl;

	return 0;
}