#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class Solution {
public:
	int MoreThanHalfNum_Solution2(vector<int> numbers) {
		int n = numbers.size();
		if (!n) {
			return 0;
		}

		int num = numbers[0];
		int cnt = 1;
		for (int i = 1; i < n; i++) {
			if (numbers[i] == num) {
				cnt++;
			}
			else {
				cnt--;
			}

			if (!cnt) {
				num = numbers[i];
				cnt++;
			}
		}

		return check(numbers, num) ? num : 0;
	}


	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int n = numbers.size();
		if (!n) {
			return 0;
		}

		int mid = n / 2;
		int index = Partition(numbers, 0, n-1);

		int low = 0, high = n-1;
		while (index != mid) {
			if (index < mid) {
				low = index + 1;
			}
			else {
				high = index - 1;
			}
			index = Partition(numbers, low, high);
		}

		return check(numbers, numbers[index]) ? numbers[index] : 0;
	}


	int Partition(vector<int> &numbers, int low, int high) {
		int randomIndex = rand() % (high - low + 1) + low;
		swap(numbers[randomIndex], numbers[high]);

		int pivot = numbers[high];
		int i = low - 1;
		for (int j = low; j <= high - 1; j++) {
			if (numbers[j] <= pivot) {
				swap(numbers[++i], numbers[j]);
			}
		}
		swap(numbers[++i], numbers[high]);

		return i;
	}

	bool check(vector<int> &numbers, int val) {
		int cnt = 0;
		for (int i = 0; i < numbers.size(); i++) {
			if (numbers[i] == val) {
				cnt++;
			}
		}

		return cnt > numbers.size() / 2;
	}
};


int main() {
	Solution s = Solution();
	vector<int> arr = {1,2,3,2,2,2,5,4,2};
	cout << s.MoreThanHalfNum_Solution2(arr) << endl;
	return 0;
}