#include <stdio.h>

int remove(int *A, int n, int elem) {
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (A[i] == elem) {
			continue;
		}
		if (i != j) {
			A[j] = A[i];
		}
		j++;
	}
	return j;
}

int main() {
	int A[] = {1,3,4,5,6,3,1,4,3,0,3};
	int n = sizeof(A) / sizeof(int);
	int elem = 3;
	int new_n = remove(A, n, elem);
	for (int i = 0; i < new_n; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
	return 0;
}