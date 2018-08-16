#include <stdio.h>
#include <stdint.h>


double myPowUnsigned(double x, unsigned int n) {
	if (n == 0) {
		return 1;
	}

	if (n == 1) {
		return x;
	}

	double curr = n % 2 ? x : 1;
	double half = myPowUnsigned(x, n/2);

	return curr * half * half;
}


double myPow(double x, int n) {
	if (x > -1e-7 && x < 1e-7) {
		if (n <= 0) {
			return -1;
		}
		return 0;
	}

	if (n < 0) {
		return 1.0 / myPowUnsigned(x, (n ^ 0xffffffff) + 1);
	}

	return myPowUnsigned(x, n);
}

int main() {
	printf("%lf\n", myPow(2.1, 3));
}