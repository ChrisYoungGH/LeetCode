class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
		vector<vector<int> > res;
		if (sum < 3) {
			return res;
		}

		int low = 1, high = 2;
		int currSum = low + high;
		while (low < (sum + 1) / 2) {
			if (currSum == sum) {
				vector<int> one;
				for (int i = low; i <= high; i++) {
					one.push_back(i);
				}
				res.push_back(one);

				high++;
				currSum += high;
			}

			else if (currSum < sum) {
				high++;
				currSum += high;
			}

			else {
				currSum -= low;
				low++;
			}
		}

		return res;
    }
};