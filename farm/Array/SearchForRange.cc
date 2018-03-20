#include <stdio.h>
#include <vector>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
	int l, r;
	l = 0, r = nums.size();

	// upper bound
	while (l < r) {
		int mid = (l + r) / 2;
		if (nums[mid] <= target) {
			l = mid + 1;
		}
		else {
			r = mid;
		}
	}
	int high = l - 1;

	// lower bound
	l = 0, r = high + 1;
	while (l < r) {
		int mid = (l + r) / 2;
		if (nums[mid] >= target) {
			r = mid;
		}
		else {
			l = mid + 1;
		}
	}
	int low = l;

	vector<int> ans;
	if (low <= high) {
		ans.push_back(low);
		ans.push_back(high);
	}
	else {
		ans.push_back(-1);
		ans.push_back(-1);
	}

	return ans;
}

int main() {
	int a[] = {1,2,3,3,5,8,10,100};
	int n = sizeof(a) / sizeof(int);
	vector<int> nums(a, a+n);

	int target = 10;
	vector<int> ans = searchRange(nums, target);
	printf("%d %d\n", ans[0], ans[1]);

	return 0;
}