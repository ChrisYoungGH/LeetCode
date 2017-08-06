#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int up = 1;
        for (int i = int(digits.size())-1; i >= 0; i--) {
            int val = digits[i] + up;
            digits[i] = val % 10;
            up = val / 10;
        }

        if (up > 0) {
            vector<int> newDigits({up});
            for (int i = 0; i < int(digits.size()); i++) {
                newDigits.push_back(digits[i]);
            }
            return newDigits;
        }

        return digits;
    }
};

int main(int argc, char const *argv[]) {
    Solution s = Solution();
    vector<int> digits;
    digits.push_back(9);
    vector<int> result = s.plusOne(digits);
    for (int i = 0; i < int(result.size()); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
