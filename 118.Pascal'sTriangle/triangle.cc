#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>  > ans;
        if (numRows <= 0) {
            return ans;
        }

        vector<int> curr;
        curr.push_back(1);
        ans.push_back(curr);

        for (int i = 1; i < numRows; i++) {
            vector<int> curr;
            curr.push_back(1);
            ans.push_back(curr);

            curr = ans[i];
            vector<int> prev = ans[i-1];

            for (int j = 1; j < i; j++) {
                curr.push_back(prev[j] + prev[j-1]);
            }
            curr.push_back(1);
            ans[i] = curr;
        }

        return ans;
    }

    vector<vector<int> > generateShortest(int numRows) {
        vector<vector<int> > r(numRows);

        for (int i = 0; i < numRows; i++) {
            r[i].resize(i + 1);
            r[i][0] = r[i][i] = 1;

            for (int j = 1; j < i; j++)
                r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
        }

        return r;
    }
};

int main() {
    Solution s = Solution();
    vector<vector<int> > ans = s.generate(5);
    for (int i = 0; i < int(ans.size()); i++) {
        vector<int> row = ans[i];
        for (int j = 0; j < int(row.size()); j++) {
            cout << row[j] << " ";
        }
        cout << endl;
    }
    return 0;
}
