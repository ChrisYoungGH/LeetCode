#include <stdio.h>
#include <vector>

using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int l = 0, r = nums.size();
    while (l < r) {
    	int mid = (l + r) / 2;
    	if (nums[mid] >= target) {
    		r = mid;
    	}
    	else {
    		l = mid + 1;
    	}
    }

    return l;
}

int main() {
	int a[] = {1,3,5,6};
	int n = sizeof(a) / sizeof(int);
	vector<int> nums(a, a+n);

	int target = 0;
	int ans = searchInsert(nums, target);
	printf("%d\n", ans);

	return 0;
}