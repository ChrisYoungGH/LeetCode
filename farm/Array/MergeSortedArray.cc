// not new array --> backwards
#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	int l = m + n - 1;
	m--; n--;
	while (m >= 0 && n >= 0) {
		nums1[l--] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
	}

	while (m >= 0) {
		nums1[l--] = nums1[m--];
	}

	while (n >= 0) {
		nums1[l--] = nums2[n--];
	}
}

int main() {

	int a[] = {1,2,3,4,5,6};
	int b[] = {2,4,6,8,10,12,14};
	int m = sizeof(a) / sizeof(int);
	int n = sizeof(b) / sizeof(int);
	vector<int> nums1(a, a + m);
	vector<int> nums2(b, b + n);
	nums1.resize(m+n);

	merge(nums1, m, nums2, n);
	for (int i = 0; i < nums1.size(); i++) {
		cout << nums1[i] << " ";
	}
	cout << endl;

	return 0;
}
