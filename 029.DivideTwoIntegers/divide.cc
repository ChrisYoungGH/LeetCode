#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int divide0(int dividend, int divisor) {
	if (divisor == 0) {
		return INT_MAX;
	}

	unsigned int u_divisor = divisor >= 0 ? divisor : (unsigned int)(-divisor);
	unsigned int u_dividend = dividend >= 0 ? dividend : (unsigned int)(-dividend);

	if (u_dividend < u_divisor) {
		return 0;
	}

	int flag = (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0) ? 1 : -1;

	unsigned int u_res = 1;
	unsigned int u_base[32] = {u_divisor, 0};
	unsigned int times[32] = {u_res, 0};

	int m = 0;
	while ((u_divisor << 1) <= u_dividend) {
		if ((u_divisor << 1) < u_divisor) {
			break;
		}

		u_res <<= 1;
		m++;
		times[m] = u_res;
		u_divisor <<= 1;
		u_base[m] = u_divisor;

		// printf("%u %u\n", u_divisor, u_res);
	}

	bool more = true;
	while (u_divisor < u_dividend) {
		while (u_divisor + u_base[m] > u_dividend) {
			m--;
			if (m < 0) {
				more = false;
				break;
			}
		}

		if (more == false) {
			break;
		}

		u_res += times[m];
		u_divisor += u_base[m];

	}

	int res = flag > 0 ? u_res : -u_res;

	if ((flag > 0 && res < 0) || (flag < 0 && res > 0)) {
		return INT_MAX;
	}

	return res;
}


int divide(int dividend, int divisor) {
	if (!divisor || (dividend == INT_MIN && divisor == -1)) {
		return INT_MAX;
	}

	int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
	long long dvd = labs(dividend);
	long long dvs = labs(divisor);
	int res = 0;
	while (dvd >= dvs) {
		long long temp = dvs;
		long long multiple = 1;
		while (dvd >= (temp << 1)) {
			temp <<= 1;
			multiple <<= 1;
		}
		dvd -= temp;
		res += multiple;
	}
	return sign == 1 ? res : -res;
}


int get_flag() {
	int x = rand() % 21 - 10;
	return (x >> 31) | (~((~x + 1) >> 31) + 1);
}

int main() {
	// srand(time(NULL));
	// for (int i = 0; i < 10; i++) {
	// 	int dividend = rand() % 1000 * get_flag();
	// 	int divisor = rand() % 100 * get_flag();
	// 	int benchmark = divisor != 0 ? dividend / divisor : INT_MAX;
	// 	int result = divide(dividend, divisor);
	// 	printf("%s: %d / %d = (b)%d, (r)%d\n", 
	// 		benchmark == result ? "Correct" : "Wrong",
	// 		dividend, divisor, benchmark, result);
	// }
	int dividend = -2147483648;
	int divisor = -1;
	printf("%d\n", divide(dividend, divisor));
	return 0;
}