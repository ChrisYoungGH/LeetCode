class Solution {
public:
    int movingCount(int threshold, int rows, int cols) {
        int *visit = new int[rows * cols];
        memset(visit, 0, sizeof(int) * rows *cols);
        
        int cnt = traverse(threshold, rows, cols, 0, 0, visit);

        delete [] visit;
        return cnt;
    }

    int traverse(int threshold, int rows, int cols, int i, int j, int *visit) {
    	if (i < 0 || i >= rows || j < 0 || j >= cols) {
    		return 0;
    	}

    	if (visit[i*cols+j] == 1 || digitSum(i) + digitSum(j) > threshold) {
    		return 0;
    	}

    	visit[i*cols+j] = 1;

    	return traverse(threshold, rows, cols, i-1, j, visit) +
	    	   traverse(threshold, rows, cols, i+1, j, visit) +
	    	   traverse(threshold, rows, cols, i, j-1, visit) +
	    	   traverse(threshold, rows, cols, i, j+1, visit) + 1;
    }

    int digitSum(int n) {
    	int sum = 0;
    	while (n) {
    		sum += n % 10;
    		n /= 10;
    	}
    	return sum;
    }
};
