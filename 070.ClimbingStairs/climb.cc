#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 0) {
            return 0;
        }
        int f1 = 1, f2 = 1;
        for (int i = 0; i < n; i++) {
            f1 = (f2 += f1) - f1;
        }
        return f1;
    }
};

int main(int argc, char const *argv[]) {
    for (int i = 0; i < 10; i++) {
        cout << (Solution()).climbStairs(i) << endl;
    }
    return 0;
}
