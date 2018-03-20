#include <stdio.h>

int missingNumber(int* nums, int n) {
 	int s = 0;
 	for (int i = 0; i < n; i++) {
 		s += nums[i];
 	}
 	return n * (n+1) / 2 - s;
}

int missingNumber2(int* nums, int n) {
 	int s = n;
 	for (int i = 0; i < n; i++) {
 		s ^= nums[i] ^ i;
 	}
 	return s;
}

int main() {
	int a[] = {9,6,4,2,3,5,7,0,1};
	int n = sizeof(a) / sizeof(int);
	printf("%d\n", missingNumber2(a, n));
	return 0;
}