#include <stdio.h>

int removeDuplicates(int *nums, int numSize) {
	int j = 0;
	int cnt = 1;
	for (int i = 1; i < numSize; i++) {
		if (nums[i] == nums[j]) {
			if (cnt >= 2) {
				continue;
			}
			cnt++;
		}
		else {
			cnt = 1;
		}
		nums[++j] = nums[i];
	}

	return numSize ? j + 1 : 0;
}

int main() {
	int A[] = {1,1,1,1,1,2,2,3,3,3,4,5,6,7,7,7,8,9,9};
	int n = sizeof(A) / sizeof(int);
	int new_n = removeDuplicates(A, n);
	for (int i = 0; i < new_n; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
	return 0;
}
