class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> unique;
        for (int i = 0; i < int(nums1.size()); i++) {
            unique[nums1[i]] = 1;
        }

        vector<int> ans;
        for (int i = 0; i <int(nums2.size()); i++) {
            if (unique[nums2[i]] == 1) {
                ans.push_back(nums2[i]);
            }
            unique[nums2[i]] = 0;
        }

        return ans;
    }
};
