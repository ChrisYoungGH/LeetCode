class Solution {
public:

    int rectCover(int n) {
        int f0 = 1, f1 = 1;
        for (int i = 0; i < n - 1; i++) {
            int tmp = f1;
            f1 = f0 + f1;
            f0 = tmp;
        }
        
        return n > 0 ? f1 : 0;
    }
};