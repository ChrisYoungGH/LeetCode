#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
            set<int>::iterator sIt = s.find(*it);
            if (sIt != s.end()) {
                return true;
            }
            s.insert(*it);
        }
        return false;
    }
};
