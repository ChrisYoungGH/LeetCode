#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

using namespace std;

double median(vector<int> &a, vector<int> &b) {
	if (a.size() == 0 && b.size() == 0) {
		return 0;
	}

	int i = 0, j = 0;
	int k = 0;
	int prev = 0, curr = 0;
	int m = a.size(), n = b.size();

	while (i < m && j < n && k < (m+n)/2) {
		if (a[i] <= b[j]) {
			prev = curr;
			curr = a[i];
			k = i + j;
			i++;
		}
		else {
			prev = curr;
			curr = b[j];
			k = i + j;
			j++;
		}
	}

	while (i < m && k < (m+n)/2) {
		prev = curr;
		curr = a[i];
		i++;
		k++;
	}

	while (j < n && k < (m+n)/2) {
		prev = curr;
		curr = b[j];
		j++;
		k++;
	}

	if ((m+n) % 2) {
		return curr;
	}
	return double(prev + curr) / 2;
}

int main() {
	int a[] = {};
	int b[] = {1};

	vector<int> va, vb;
	for (int i = 0; i < sizeof(a)/sizeof(int); i++) {
		va.push_back(a[i]);
	}
	for (int i = 0; i < sizeof(b)/sizeof(int); i++) {
		vb.push_back(b[i]);
	}

	double m = median(va, vb);
	printf("%lf\n", m);

	return 0;
}