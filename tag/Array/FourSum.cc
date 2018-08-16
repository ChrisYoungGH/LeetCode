#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > fourSum(vector<int> &nums, int target) {
	sort(nums.begin(), nums.end());
	
	int n = nums.size();
	vector<vector<int> > res;

	for (int i = 0; i < n - 3; i++) {
		if (i != 0 && nums[i] == nums[i-1]) {
			continue;
		}

		for (int j = i + 1; j < n - 2; j++) {
			int l = j + 1, h = n - 1;

			if (j != i + 1 && nums[j] == nums[j-1]) {
				continue;
			}

			while (l < h) {
				int sum = nums[i] + nums[j] + nums[l] + nums[h];
				if (sum == target) {
					vector<int> item = {nums[i], nums[j], nums[l], nums[h]};
					res.push_back(item);

					while (l < h && nums[l] == nums[l+1]) l++;
					while (l < h && nums[h] == nums[h-1]) h--;
					l++; h--;
				}
				
				else if (sum < target) {
					l++;
				}
				else {
					h--;
				}
			}
		}
	}

	return res;
}

int main() {
	vector<int> nums = {1, 0, -1, 0, -2, 2};
	int target = 0;
	vector<vector<int> > res = fourSum(nums, target);

	for (int i = 0; i < res.size(); i++) {
		cout << res[i][0] << " " << res[i][1] << " " << res[i][2] << " " << res[i][3] << endl;
	}

	return 0;
}