class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
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
                    while (l < r && nums[l] == nums[l+1]) l++;
                    while (l < r && nums[r] == nums[r-1]) r--;
                }

                if (sum < target) l++;
                else r--;
            }
        }

        return ans;
    }
};
