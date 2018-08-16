#include <stdio.h>
#include <stdint.h>

int hammingWeight(uint32_t n) {
    int s = 0;
    while (n) {
    	s += n % 2;
    	n >>= 1;
    }
    return s;
}

int main() {
	printf("%d\n", hammingWeight(11));
	return 0;
}