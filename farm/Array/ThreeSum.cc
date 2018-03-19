#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > threeSum(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	
	vector<vector<int> > res;    
	for (int i = 0; i < int(nums.size()) - 2; i++) {
		if (i != 0 && nums[i] == nums[i-1]) {
			continue;
		}

		int l = i + 1, m = nums.size() - 1;
		while (l < m) {
			int s = nums[i] + nums[l] + nums[m];
			if (s == 0) {
				vector<int> v = {nums[i], nums[l], nums[m]};
				res.push_back(v);

				l++; m--;
				while (l < m && nums[l] == nums[l-1]) l++;
				while (m > l && nums[m] == nums[m+1]) m--;
			}
			else if (s > 0) {
				m--;
			}
			else {
				l++;
			}
			
		}
	}

	return res;
}

int main() {
	vector<int> nums = {-1,1,-1,0};
	vector<vector<int> > res = threeSum(nums);

	for (int i = 0; i < res.size(); i++) {
		printf("%d %d %d\n", res[i][0], res[i][1], res[i][2]);
	}

	return 0;
}