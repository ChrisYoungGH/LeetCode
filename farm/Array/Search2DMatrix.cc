#include <iostream>
#include <vector>

using namespace std;


bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    if (m == 0) {
    	return false;
    }
    int n = matrix[0].size();
    if (n == 0) {
    	return false;
    }

    int i = 0, j = n-1;
    while (i <= m-1 && j >= 0) {
    	int curr = matrix[i][j];
    	if (curr == target) {
    		return true;
    	}
    	if (target > curr) {
    		i++;
    	}
    	else {
    		j--;
    	}
    }

    return false;
}

int main() {

}