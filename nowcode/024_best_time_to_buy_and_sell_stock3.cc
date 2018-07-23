#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int hold1 = INT_MIN, hold2 = INT_MIN;
        int release1 = 0, release2 = 0;

        for (int p : prices) {
        	release2 = max(release2, hold2 + p);
        	hold2 = max(hold2, release1 - p);
        	release1 = max(release1, hold1 + p);
        	hold1 = max(hold1, -p);
        }

        return release2;
    }
};

int main() {
	vector<int> prices = {3,3,5,0,0,3,1,4};

	Solution s = Solution();
	cout << s.maxProfit(prices) << endl;

	return 0;
}