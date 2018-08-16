#include <stdio.h>
#include <vector>

using namespace std;

int findPeakElement(vector<int>& nums) {
	int n = int(nums.size());
	int l = 0, r = n - 1;
	while (l < n && r > -1 && l < r) {
		int mid = (l + r) / 2;
		if ((mid == 0 || nums[mid] > nums[mid-1]) && 
			(mid == n-1 || nums[mid] > nums[mid+1])) {
			return mid;
		}
		if (mid != 0 && nums[mid] <= nums[mid-1]) {
			r = mid - 1;
		}
		else if (mid != n && nums[mid] <= nums[mid+1]) {
			l = mid + 1;
		}
		else {
			return mid;
		}
	}

	if (l == n) {
		return n-1;
	}
	if (r == -1) {
		return 0;
	}
	return l;
}

int main() {
	int a[] = {1,2};
	int n = sizeof(a) / sizeof(int);
	vector<int> nums(a, a+n);

	int target = 0;
	int ans = findPeakElement(nums);
	printf("%d\n", ans);

	return 0;
}

