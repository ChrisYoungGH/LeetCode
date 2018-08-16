class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int split_pos = -1;
        for (int i = n-1; i > 0; i--) {
        	if (nums[i-1] < nums[i]) {
        		split_pos = i-1;
        		break;
        	}
        }
        if (split_pos == -1) {
        	sort(nums.begin(), nums.end());
        	return;
        }

        for (int i = n-1; i > split_pos; i--) {
        	if (nums[i] > nums[split_pos]) {
        		swap(nums[i], nums[split_pos]);
        		break;
        	}
        }
        sort(nums.begin() + split_pos + 1, nums.end());
    }
};

