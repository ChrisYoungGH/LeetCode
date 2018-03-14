class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int n = int(nums.size()), m = int(nums[0].size());

        if (r * c != n * m) {
            return nums;
        }

        vector<vector<int>> ans;
        ans.resize(r);
        for (int i = 0; i < r; i++) {
            ans[i].resize(c);
        }
        for (int i = 0; i < r * c; i++) {
            ans[i/c][i%c] = nums[i/m][i%m];
        }

        return ans;
    }
};
