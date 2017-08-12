class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> m;
        for (int i = 0; i < int(nums.size()); i++) {
            int count = 0;
            map<int,int>::iterator it = m.find(nums[i]);
            if (it != m.end()) {
                count = it->second;
            }
            m[nums[i]] = ++count;
            if (count > int(nums.size()) / 2) {
                return nums[i];
            }
        }
        return -1;
    }
};
