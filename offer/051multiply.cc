// 可以看作是对角线为1 的矩阵的每行乘积, 分别计算上下三角矩阵即可, 复杂度O(n)

class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
    	vector<int> B;
    	int n = A.size();
    	if (!n) {
    		return B;
    	}

    	vector<int> BDown(n), BUp(n);
    	BDown[0] = 1;
    	for (int i = 1; i < n; i++) {
    		BDown[i] = BDown[i-1] * A[i-1];
    	}
    	BUp[n-1] = 1;
    	for (int i = n-2; i >= 0; i--) {
    		BUp[i] = BUp[i+1] * A[i+1];
    	}

    	B.resize(n);
    	for (int i = 0; i < n; i++) {
    		B[i] = BDown[i] * BUp[i];
    	}

    	return B;
    }
};