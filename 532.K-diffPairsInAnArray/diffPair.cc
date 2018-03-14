class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) {
            return 0;
        }

        map<int,int> m;
        for (int i = 0; i < int(nums.size()); i++) {
            map<int,int>::iterator it = m.find(nums[i]);
            if (it == m.end()) {
                m[nums[i]] = 0;
            }
            m[nums[i]]++;
        }

        int count = 0;

        if (k > 0) {
            for (map<int,int>::iterator it = m.begin(); it != m.end(); ++it) {
                map<int,int>::iterator hit = m.find(it->first + k);
                if (hit != m.end()) {
                    count++;
                }
            }
        }
        else {
            for (map<int,int>::iterator it = m.begin(); it != m.end(); ++it) {
                if (it->second > 1) {
                    count++;
                }
            }
        }

        return count;
    }
};
