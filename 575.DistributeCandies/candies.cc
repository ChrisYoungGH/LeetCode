class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        set<int> candySet;
        for (int c : candies) {
            candySet.insert(c);
        }

        return min(candySet.size(), candies.size() / 2);
    }
};
