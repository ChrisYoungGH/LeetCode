#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMin0(vector<int> &nums) {
	for (int i = 0; i < int(nums.size()) - 1; i++) {
		if (nums[i] > nums[i+1]) {
			return nums[i+1];
		}
	}
	return nums[0];
}

// binary search
int findMin(vector<int> &nums) {
	int l = 0, r = int(nums.size()) - 1;
	
	if (nums[l] < nums[r]) {
		return nums[0];
	}
	
	while (l < r - 1) {
		int m = (l + r) / 2;
		if (nums[m] < nums[l]) {
			r = m;
		}
		else {
			l = m;
		}
	}

	return nums[r];
}

int main() {
	int a[] = {4,5,6,7,0,1,2};
	int n = sizeof(a) / sizeof(int);
	vector<int> nums(a, a + n);
	cout << findMin(nums) << endl;

	return 0;
}