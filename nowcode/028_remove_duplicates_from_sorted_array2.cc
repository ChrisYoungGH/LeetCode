class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int newLen = 0;
        int i = 0;
        int currCnt = 0;
        // int n = A.size();
        while (i < n) {
        	if (!i || A[i] != A[i-1]) {
        		A[newLen++] = A[i];
        		currCnt = 1;
        	}
        	else {
        		currCnt++;
        		if (currCnt <= 2) {
        			A[newLen++] = A[i];
        		}
        	}

        	i++;
        }

        return newLen;
    }
};