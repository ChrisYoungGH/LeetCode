class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> m;
        for (int i = 0; i < int(nums.size()); i++) {
            map<int,int>::iterator it = m.find(nums[i]);
            if (it != m.end()) {
                int index = m[nums[i]];
                if (i - index <= k) {
                    return true;
                }
            }
            m[nums[i]] = i;
        }

        return false;
    }
};
