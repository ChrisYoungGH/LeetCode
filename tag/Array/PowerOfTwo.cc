#include <stdio.h>

bool isPowerOfTwo(int n) {
    while (n > 1) {
    	if (n % 2) {
    		return 0;
    	}
    	n >>= 1;
    }
    return n == 1;
}

int main() {
	printf("%d\n", isPowerOfTwo(-16));
}