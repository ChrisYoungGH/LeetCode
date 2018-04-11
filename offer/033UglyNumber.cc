#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
		if (index <= 0)   {
			return 0;
		}

		vector<int> uglyNums(index);
		uglyNums[0] = 1;

		int split2 = 0, split3 = 0, split5 = 0;

		for (int i = 1; i < index; i++) {
			uglyNums[i] = min(uglyNums[split2] * 2, min(uglyNums[split3] * 3, uglyNums[split5] * 5));

			while (uglyNums[split2] * 2 <= uglyNums[i]) split2++;
			while (uglyNums[split3] * 3 <= uglyNums[i]) split3++;
			while (uglyNums[split5] * 5 <= uglyNums[i]) split5++;
		}

		return uglyNums.back();
    }
};

int main() {
	Solution s = Solution();
	cout << s.GetUglyNumber_Solution(1500) << endl;
	return 0;

}