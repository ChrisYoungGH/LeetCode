#include <iostream>
#include <cstring>

using namespace std;

class Solution {
public:
    bool hasPath(char *matrix, int rows, int cols, char *str) {
    	if (!matrix || !str || rows <= 0 || cols <= 0) {
    		return false;
    	}

    	int *visit = new int[rows * cols];
    	memset(visit, 0, sizeof(int) * rows * cols);

    	bool flag = false;
    	for (int i = 0; i < rows; i++) {
    		for (int j = 0; j < cols; j++) {

    			if (traverse(matrix, str, rows, cols, i, j, visit)) {
    				flag = true;
    				break;
    			}
    		}
    	}

    	delete [] visit;
    	return flag;
    }


    bool traverse(char *matrix, char *str, int rows, int cols, int i, int j, int *visit) {
    	if (*str == '\0') {
    		return true;
    	}

    	if (i < 0 || i >= rows || j < 0 || j >= cols) {
    		return false;
    	}

    	int index = i * cols + j;
    	if (matrix[index] != *str || visit[index] == 1) {
    		return false;
    	}

    	visit[index] = 1;

    	if (traverse(matrix, str + 1, rows, cols, i-1, j, visit) ||
			traverse(matrix, str + 1, rows, cols, i+1, j, visit) ||
			traverse(matrix, str + 1, rows, cols, i, j-1, visit) ||
			traverse(matrix, str + 1, rows, cols, i, j+1, visit)) {

    		return true;
    	}

    	visit[index] = 0;

    	return false;
    }

};


int main() {
	Solution s1 = Solution();

	char m[100];
	char s[100];

	strcpy(m, "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS");
 	strcpy(s, "SGGFIECVAASABCEHJIGQEM");
	cout << s1.hasPath(m,5,8,s) << endl;

	return 0;
}