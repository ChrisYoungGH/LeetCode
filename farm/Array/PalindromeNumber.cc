#include <stdio.h>

bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }
    if (x == 0) {
        return true;
    }

    long h = 1;
    int xt = x;
    while (xt) {
        xt /= 10;
        h *= 10;
    }

    long l = 10;

    while (l < h) {
        int hb = x % h / (h/10);
        int lb = x % l / (l/10);
        if (hb != lb) {
            return false;
        }
        h /= 10;
        l *= 10;
    }

    return true;
}

bool isPalindrome2(int x) {
    if (x < 0) {
        return false;
    }
    if (x == 0) {
        return true;
    }

    int t = x;
    int y = 0;

    while (t) {
        y = y * 10 + t % 10;
        t /= 10;
    }

    return y == x;
}

int main() {
    int x = 1000000001;
    printf("%d\n", isPalindrome2(x));
    return 0;
}