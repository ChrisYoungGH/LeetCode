#include <stdio.h>
#include <stdlib.h>

bool invalid = false;

double power(double base, int exp) {
	if (base > -1e-8 && base < 1e-8) {
		if (exp <= 0) {
			invalid = true;
		}
		return 0;
	}

	if (exp < 0) {
		return 1.0 / power(base, -exp);
	}

	if (exp == 0) {
		return 1;
	}
	if (exp == 1) {
		return base;
	}

	double half = power(base, exp);

	return half * half * (exp % 2 ? base : 1.0);
}

int main() {
	double base = 3;
	int exp = -1;
	double result = power(base, exp);
	if (!invalid) {
		printf("%lf\n", result);
	}
	else {
		printf("invalid input\n");
	}
	return 0;
}