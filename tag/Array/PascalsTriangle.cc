#include <stdio.h>
#include <vector>
using namespace std;

vector<vector<int> > generate(int numRows) {
	vector<vector<int> > res(numRows);

	for (int i = 0; i < numRows; i++) {
		res[i].resize(i+1);
		res[i][0] = res[i][res[i].size()-1] = 1;
		
		for (int j = 1; j < i; j++) {
			res[i][j] = res[i-1][j-1] + res[i-1][j];
		}
	}

	return res;
}

int main() {
	vector<vector<int> > res = generate(8);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			printf("%d ", res[i][j]);
		}
		printf("\n");
	}

	return 0;
}