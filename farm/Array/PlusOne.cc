#include <stdio.h>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
	vector<int> res(digits.size(), 0);
	int up = 1;
	for (int i = int(digits.size()) - 1; i >= 0; i--) {
		int sum = digits[i] + up;
		res[i] = sum % 10;
		up = sum / 10;
	}

	if (up) {
		res.insert(res.begin(), 1);
	}

	return res;
}

int main() {
	vector<int> digits {9,9,9,9};
	vector<int> res = plusOne(digits);
	for (int i = 0; i < res.size(); i++) {
		printf("%d", res[i]);
	}
	printf("\n");

	return 0;
}