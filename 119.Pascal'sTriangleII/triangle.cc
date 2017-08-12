#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        ans.push_back(1);
        for (int i = 1; i < rowIndex+1; i++) {
            ans.push_back(1);
            for (int j = i-1; j >= 1; j--) {
                ans[j] += ans[j-1];
            }
        }
        return ans;
    }

};

int main(int argc, char const *argv[]) {
    Solution s = Solution();
    vector<int> ans = s.getRow(3);
    for (int i = 0; i < int(ans.size()); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
