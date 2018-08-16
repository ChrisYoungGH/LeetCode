class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // begin at pos: m+n-1
        int i = m + n - 1;
        m--; n--;
        while (m >= 0 && n >= 0) {
        	A[i--] = A[m] > B[n] ? A[m--] : B[n--];
        }
        while (m >= 0) {
        	A[i--] = A[m--];
        }
        while (n >= 0) {
        	A[i--] = B[n--];
        }
    }
};