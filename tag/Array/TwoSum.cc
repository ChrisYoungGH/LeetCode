#include <stdio.h>
#include <vector>
#include <map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	map<int, int> m;
	vector<int> res(2);
	for (int i = 0; i < nums.size(); i++) {
		map<int,int>::iterator it = m.find(nums[i]);
		if (it != m.end()) {
			res[0] = it->second;
			res[1] = i;
			break;
		}
		m[target - nums[i]] = i;
	}
	return res;
}

int main() {
	int arr[] = {3,3};
	vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));
	int target = 6;
	vector<int> res = twoSum(nums, target);
	printf("%d %d\n", res[0], res[1]);
	return 0;
}