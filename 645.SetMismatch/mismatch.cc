class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int* counts = new int[nums.size()];
        vector<int> ans;
        for (int n : nums) {
            counts[n-1]++;
            if (counts[n-1] > 1) {
                ans.push_back(n);
            }
        }
        for (int i = 0; i < int(nums.size()); i++) {
            if (counts[i] == 0) {
                ans.push_back(i + 1);
                break;
            }
        }
        return ans;
    }
};
