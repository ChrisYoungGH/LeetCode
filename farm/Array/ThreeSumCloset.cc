#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

int threeSumClosest(vector<int> &nums, int target) {
	int minDist = INT_MAX, ans;

	sort(nums.begin(), nums.end());

	for (int i = 0; i < (nums.size()) - 2; i++) {
		int l = i + 1, h = nums.size() - 1;

		if (i != 0 && nums[i] == nums[i-1]) {
			continue;
		}

		while (l < h) {
			int sum = nums[i] + nums[l] + nums[h];

			if (sum == target) {
				return sum;
			}

			int dist = abs(sum - target);
			if (dist < minDist) {
				minDist = dist;
				ans = sum;
				// skip same elements but remain one
				while (l + 1 < h && nums[l] == nums[l+1] && nums[l] == nums[l+2]) {
					l++;
				}
				while (l + 1 < h && nums[h] == nums[h-1] && nums[h] == nums[h-2]) {
					h--;
				}
			}

			if (sum < target) {
				l++;
			}
			else {
				h--;
			}
		}
	}

	return ans;
}


int threeSumClosest2(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());

    int ans = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < int(nums.size()) - 2; i++) {
        if (i != 0 && nums[i] == nums[i-1]) {
            continue;
        }

        int l = i + 1, r = int(nums.size()) - 1;
        while (l < r) {

            int sum = nums[i] + nums[l] + nums[r];
            if (sum == target) {
                return sum;
            }

            if (abs(sum - target) < abs(ans - target)) {
                ans = sum;
                while (l+1 < r && nums[l] == nums[l+1] && nums[l] == nums[l+2]) {
                	l++;
                }
                while (l+1 < r && nums[r] == nums[r-1] && nums[r] == nums[r-2]) {
                	r--;
                }
            }

            if (sum < target) l++;
            else r--;
        }
    }

    return ans;
}


int main() {
	int S[] = {-100,-20,-19,-19,-18};
	int n = sizeof(S) / sizeof(int);
	vector<int> nums(S, S + n);
	int target = -58;
	cout << threeSumClosest(nums, target) << endl;
	cout << threeSumClosest2(nums, target) << endl;
	return 0;
}