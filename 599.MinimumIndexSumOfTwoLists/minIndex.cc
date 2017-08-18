class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string, int> counts;
        for (int i = 0; i < int(list1.size()); i++) {
            counts[list1[i]] = i;
        }

        vector<string> ans;
        int minIndex = list1.size() + list2.size();
        for (int i = 0; i < int(list2.size()); i++) {
            string v = list2[i];
            if (counts.find(v) == counts.end()) {
                continue;
            }
            int sumIndex = counts[v] + i;
            if (sumIndex < minIndex) {
                minIndex = sumIndex;
                ans.clear();
                ans.push_back(v);
            }
            else if (sumIndex == minIndex) {
                ans.push_back(v);
            }
        }

        return ans;
    }
};
