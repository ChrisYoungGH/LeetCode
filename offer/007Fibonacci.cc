class Solution {
public:
    int Fibonacci(int n) {
        if (n <= 0) {
            return 0;
        }
        if (n <= 2) {
            return 1;
        }
        
        int f1 = 1, f2 = 1;
        for (int i = 0; i < n - 2; i++) {
            int tmp = f2;
            f2 = f1 + f2;
            f1 = tmp;
        }
        
        return f2;
    }

};