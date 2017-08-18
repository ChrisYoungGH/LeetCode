class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int> counts;
        for (int n : nums) {
            counts[n]++;
        }

        int maxLen = 0;
        for (map<int,int>::iterator it = counts.begin(); it != counts.end(); ++it) {
            int key = it->first;
            if (counts.find(key-1) != counts.end()) {
                maxLen = max(maxLen, counts[key] + counts[key-1]);
            }
            if (counts.find(key+1) != counts.end()) {
                maxLen = max(maxLen, counts[key] + counts[key+1]);
            }
        }

        return maxLen;
    }
};
