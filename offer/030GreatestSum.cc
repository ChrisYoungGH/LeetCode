class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> &arr) {
		int n = arr.size();
		if (!n) {
			return 0;
		}

		int globalMaxSum = arr[0];
		int currMaxSum = arr[0];

		for (int i = 1; i < n; i++) {
			currMaxSum = max(currMaxSum + arr[i], arr[i]);
			globalMaxSum = max(globalMaxSum, currMaxSum);
		}

		return globalMaxSum;
	}
};