class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if (m > n) {
        	swap(A, B);
        	swap(m, n);
        }

        if (n == 0) {
        	return -1;
        }

        int imin = 0, imax = m;
        int half_len = (m + n + 1) / 2; // ensure len(left) >= len(right) and mid stays at left

        while (imin <= imax) {
        	int i = (imin + imax) / 2;
        	int j = half_len - i;

        	if (i < m && B[j-1] > A[i]) {
        		imin = i + 1;
        	}
        	else if (i > 0 && A[i-1] > B[j]) {
        		imax = i - 1;
        	}
        	else {
        		int max_left;
        		if (i == 0) {
        			max_left = B[j-1];
        		}
        		else if (j == 0) {
        			max_left = A[i-1];
        		}
        		else {
        			max_left = max(A[i-1], B[j-1]);
        		}

        		int min_right;
        		if (i == m) {
        			min_right = B[j];
        		}
        		else if (j == n) {
        			min_right = A[i];
        		}
        		else {
        			min_right = min(A[i], B[j]);
        		}

    			return (m + n) % 2 ? max_left : (max_left + min_right) / 2.0;
        	}
        }
        
        return -1;
    }
};