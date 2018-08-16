class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> result;

        int m = matrix.size();
        if (!m) {
        	return result;
        }

        int n = matrix[0].size();
        if (!n) {
        	return result;
        }

        int i = 0, j = 0;
        int l = 0, r = n-1, t = 0, b = m-1;
        while (l <= r && t <= b) {
        	for (int j = l; j <= r; j++) {
        		result.push_back(matrix[t][j]);
        	}
        	t++;
        	if (t > b) break;

        	for (int i = t; i <= b; i++) {
        		result.push_back(matrix[i][r]);
        	}
        	r--;
        	if (r < l) break;

        	for (int j = r; j >= l; j--) {
        		result.push_back(matrix[b][j]);
        	}
        	b--;
        	if (b < t) break;

        	for (int i = b; i >= t; i--) {
        		result.push_back(matrix[i][l]);
        	}
        	l++;
        	if (l > r) break;
        }

        return result;
    }
};