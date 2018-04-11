#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
	vector<int> GetLeastNumbers_Solution2(vector<int> &input, int k) {
		vector<int> res;

		int n = input.size();
		if (!n || k <= 0 || k > n) {
			return res;
		}

		multiset<int, greater<int> > leastNums;

		for (int i = 0; i < n; i++) {
			if (leastNums.size() < k) {
				leastNums.insert(input[i]);
			}
			else {
				multiset<int, greater<int> >::iterator it = leastNums.begin();
				if (*it > input[i]) {
					leastNums.erase(*it);
					leastNums.insert(input[i]);
				}
			}
		}

		for (multiset<int, greater<int> >::iterator it = leastNums.begin(); it != leastNums.end(); ++it) {
			res.push_back(*it);
		}

		return res;
	}


	vector<int> GetLeastNumbers_Solution(vector<int> &input, int k) {
		vector<int> res;

		int n = input.size();
		if (!n || k <= 0 || k > n) {
			return res;
		}

		if (k == n) {
			for (int i = 0; i < n; i++) {
				res.push_back(input[i]);
			}

			return res;
		}

		int low = 0, high = n - 1;
		int index = Partition(input, low, high);

		while (index != k) {
			if (index < k) {
				low = index + 1;
			}
			else {
				high = index - 1;
			}
			index = Partition(input, low, high);
		}

		for (int i = 0; i < k; i++) {
			res.push_back(input[i]);
		}

		return res;
	}

	int Partition(vector<int> &arr, int low ,int high) {
		int randomIndex = rand() % (high - low + 1) + low;
		swap(arr[randomIndex], arr[high]);

		int pivot = arr[high];
		int i = low - 1;
		for (int j = low; j <= high - 1; j++) {
			if (arr[j] < pivot) {
				swap(arr[++i], arr[j]);
			}
		}
		swap(arr[++i], arr[high]);

		return i;
	}
};


int main() {
	vector<int> input = {4,5,1,6,2,7,3,8};
	Solution s = Solution();
	vector<int> output = s.GetLeastNumbers_Solution2(input, 4);
	for (int i = 0; i < output.size(); i++) {
		cout << output[i] << " ";
	}
	cout << endl;

	return 0;
}