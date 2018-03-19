#include <stdio.h>
#include <vector>
using namespace std;

vector<int> getRow(int rowIndex) {
	vector<int> res(rowIndex+1, 0);
	res[0] = 1;
	for (int i = 0; i < rowIndex; i++) {
		for (int j = i+1; j >= 1; j--) {
			res[j] += res[j-1];
		}
	}
	return res;
}

int main() {
	vector<int> res = getRow(6);
	for (int i = 0; i < res.size(); i++) {
		printf("%d ", res[i]);
	}
	printf("\n");

	return 0;
}
