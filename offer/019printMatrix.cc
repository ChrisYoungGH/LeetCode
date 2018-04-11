class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > &matrix) {
		vector<int> res;

		int m = matrix.size();
		int n = m ? matrix[0].size() : 0;
		if (!m || !n) {
			return res;
		}

		int rBegin = 0, rEnd = m - 1, cBegin = 0, cEnd = n - 1;
		int i = 0, j = 0;

		while (rBegin <= rEnd && cBegin <= cEnd) {
			if (cBegin > cEnd) break;
			for (j = cBegin; j <= cEnd; j++) {
				res.push_back(matrix[i][j]);
			}
			j--;
			rBegin++;

			if (rBegin > rEnd) break;
			for (i = rBegin; i <= rEnd; i++) {
				res.push_back(matrix[i][j]);
			}
			i--;
			cEnd--;

			if (cBegin > cEnd) break;
			for (j = cEnd; j >= cBegin; j--) {
				res.push_back(matrix[i][j]);
			}
			j++;
			rEnd--;

			if (rBegin > rEnd) break;
			for (i = rEnd; i >= rBegin; i--) {
				res.push_back(matrix[i][j]);
			}
			i++;
			cBegin++;
		}

		return res;
	}
};