class Solution {
public:
	int InversePairs(vector<int> &data) {
		int n = data.size();
		if(!n) {
			return 0;
		}

		vector<int> copy = data;

		return InversePairsCore(data, copy, 0, n-1) % 1000000007;
	}

	long InversePairsCore(vector<int> &data, vector<int> &copy, int low, int high) {
		if (low == high) {
			copy[low] = data[low];
			return 0;
		}

		int len = (high - low) / 2;

		long left = InversePairsCore(copy, data, low, low + len);
		long right = InversePairsCore(copy, data, low + len + 1, high);

		int i = low + len, j = high;
		int indexCopy = high;
		long count = 0;

		while (i >= low && j >= low + len + 1) {
			if (data[i] > data[j]) {
				count += j - low - len;
				copy[indexCopy--] = data[i--];
			}
			else {
				copy[indexCopy--] = data[j--];
			}
		}

		while (i >= low) {
			copy[indexCopy--] = data[i--];
		}
		while (j >= low + len + 1) {
			copy[indexCopy--] = data[j--];
		}

		return left + right + count;
	}
};