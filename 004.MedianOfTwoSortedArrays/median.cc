#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

using namespace std;

double median(vector<int> &nums1, vector<int> &nums2) {

	int m = nums1.size(), n = nums2.size();

	if (m + n == 0) {
		return 0;
	}

	// when there is totaly 1 element
	int prev = 0, curr = 0;
	if (m == 0) {
		curr = nums2[0];
	}
	else if (n == 0) {
		curr = nums1[0];
	}

	int i = 0, j = 0, k = 0;

	// choose the small one
	while (i < m && j < n && k < (m+n)/2) {
		if (nums1[i] <= nums2[j]) {
			prev = curr;
			curr = nums1[i];
			k = i + j;
			i++;
		}
		else {
			prev = curr;
			curr = nums2[j];
			k = i + j;
			j++;
		}
	}

	// process remained
	while (i < m && k < (m+n)/2) {
		prev = curr;
		curr = nums1[i];
		k = i + j;
		i++;
	}

	while (j < n && k < (m+n)/2) {
		prev = curr;
		curr = nums2[j];
		k = i + j;
		j++;
	}

	// return condition
	if ((m+n) % 2) {
		return curr;
	}
	return double(prev + curr) / 2;
}

int main() {
	int nums1[] = {1};
	int nums2[] = {};

	vector<int> va, vb;
	for (int i = 0; i < sizeof(nums1)/sizeof(int); i++) {
		va.push_back(nums1[i]);
	}
	for (int i = 0; i < sizeof(nums2)/sizeof(int); i++) {
		vb.push_back(nums2[i]);
	}

	double m = median(va, vb);
	printf("%lf\n", m);

	return 0;
}