#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int>& nums) {
	int n = nums.size();
	int a = 0, b = 0;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			a = max(a + nums[i], b);
		}
		else {
			b = max(b + nums[i], a);
		}
	}

	return max(a, b);
}

int main() {
	vector<int> nums = {13,37,23,12,15,27,18};
	cout << rob(nums) << endl;
	return 0;
}