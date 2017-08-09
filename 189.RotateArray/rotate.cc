class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        if (k == 0) {
            return;
        }
        vector<int> tmp;
        tmp.resize(k);
        copy(tmp, k, nums, nums.size(), k);
        copy(nums, nums.size(), nums, nums.size()-k, nums.size()-k);
        copy(nums, k, tmp, k, k);
    }

    void copy(vector<int>& dest, int dest_idx, vector<int>& src, int src_idx, int k) {
        for (int i = k; i > 0; i--) {
            dest[--dest_idx] = src[--src_idx];
        }
    }


    void rotate2(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums, 0, nums.size());
        reverse(nums, 0, k);
        reverse(nums, k, nums.size());
    }

    void reverse(vector<int>& nums, int low, int high) {
        int len = high - low;
        for (int i = 0; i < len / 2; i++) {
            int tmp = nums[low + i];
            nums[low + i] = nums[high - i - 1];
            nums[high - i - 1] = tmp;
        }
    }
};
