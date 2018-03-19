#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    int j = 0;
    for (int i = 1; i < numsSize; i++) {
    	if (nums[i] == nums[j]) {
    		continue;
    	}
    	nums[++j] = nums[i];
    }
    return numsSize > 0 ? j+1 : 0;
}

int main() {
	int A[] = {};
	int n = sizeof(A) / sizeof(int);
	int new_n = removeDuplicates(A, n);
	for (int i = 0; i < new_n; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
	return 0;
}

