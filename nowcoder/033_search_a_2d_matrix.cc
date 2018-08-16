class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int n = matrix.size();
        if (!n) {
        	return false;
        }
        int m = matrix[0].size();
        if (!m) {
        	return false;
        }

        int i = 0, j = m-1;
        while (i >= 0 && i < n && j >= 0 && j < n) {
        	if (target == matrix[i][j]) {
        		return true;
        	}
        	if (target > matrix[i][j]) {
        		i++;
        	}
        	else {
        		j--;
        	}
        }
        return false;
    }
};