#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (!n) {
        	return 0;
        }

        int global_max = 0;
        int min = prices[0];
        for (int i = 1; i < n; i++) {
        	if (prices[i] < prices[i-1]) {
        		global_max += prices[i-1] - min;
        		min = prices[i];
        	}
        }

        if (prices[n-1] > min) {
        	global_max += prices[n-1] - min;
        }

        return global_max;
    }
};

int main() {
	vector<int> vec = {7,6,4,3,1};
	Solution s = Solution();
	cout << s.maxProfit(vec) << endl;
	return 0;
}

