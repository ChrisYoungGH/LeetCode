class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        for (int i = 0; i < int(nums.size()) - 2; i++) {
            int l = i + 1, h = nums.size() - 1;

            if (i != 0 && nums[i] == nums[i-1]) {
                continue;
            }

            while (l < h) {
                int part = nums[l] + nums[h] + nums[i];
                if (part == 0) {
                    vector<int> one = {nums[i], nums[l], nums[h]};
                    ans.push_back(one);

                    while (l < h && nums[l] == nums[l+1]) l++;
                    while (l < h && nums[h] == nums[h-1]) h--;
                    l++; h--;
                }

                else if (part < 0) l++;
                else h--;
            }
        }

        return ans;
    }
};
