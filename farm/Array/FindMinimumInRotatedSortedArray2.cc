#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMin(vector<int> &nums) {
	int l = 0, r = int(nums.size()) - 1;
	
	// [l,r] is sorted
	if (nums[l] < nums[r]) {
		return nums[l];
	}

	while (l < r - 1) {
		int m = (l + r) / 2;
		if (nums[m] > nums[l]) {
			l = m;
		}
		else if (nums[m] < nums[l]) {
			r = m;
		}
		else {	// nums[m] == nums[l]
			if (nums[m] > nums[r]) {
				l = m;
			}
			else {	// nums[m] == nums[r]
				l++;

				// [l,r] is sorted
				if (nums[l] < nums[r]) {
					return nums[l];
				}
			}
		}
	}

	return min(nums[l], nums[r]);
}

int main() {
	int a[] = {1,3,3};
	int n = sizeof(a) / sizeof(int);
	vector<int> nums(a, a + n);
	cout << findMin(nums) << endl;

	return 0;
}

/**
1,1,0,1
1,0,1,1,1
*/