class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int newLen = 0;
        for (int i = 0; i < n; i++) {
        	if (A[i] != elem) {
        		A[newLen++] = A[i];
        	}
        }
        return newLen;
    }
};

class Solution2 {
public:
    int removeElement(int A[], int n, int elem) {
        int newLen = 0;
        for (int i = 0; i < n; i++) {
        	if (A[i] == elem) {
        		swap(A[i--], A[--n]);
        	}
        }
        return n;
    }
};