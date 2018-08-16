#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char> > &board) {
        int m = board.size();
        if (!m) {
        	return;
        }
        int n = board[0].size();
        if (!n) {
        	return;
        }

        vector<vector<int> > visit;
        for (int i = 0; i < m; i++) {
        	vector<int> v(n, 0);
        	visit.push_back(v);
        }

        for (int j = 0; j < n; j++) {
        	traverse(board, visit, 0, j);
        }
        for (int j = 0; j < n; j++) {
        	traverse(board, visit, m-1, j);
        }
        for (int i = 1; i < m-1; i++) {
        	traverse(board, visit, i, 0);
        }
        for (int i = 1; i < m-1; i++) {
        	traverse(board, visit, i, n-1);
        }

        for (int i = 1; i < m-1; i++) {
        	for (int j = 1; j < n-1; j++) {
        		if (!visit[i][j] && board[i][j] == 'O') {
        			board[i][j] = 'X';
        		}
        	}
        }
    }

    void traverse(vector<vector<char> > &board, vector<vector<int> > &visit, int i, int j) {
    	int m = board.size(), n = board[0].size();

    	if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] == 'X') {
    		return;
    	}

    	if (visit[i][j]) {
    		return;
    	}

    	visit[i][j] = 1;

    	traverse(board, visit, i-1, j);
    	traverse(board, visit, i+1, j);
    	traverse(board, visit, i, j-1);
    	traverse(board, visit, i, j+1);
    }
};


void display(vector<vector<char> > &board) {
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
	char arr[][6] = {{'O','X','O','O','X','X'},{'O','X','X','X','O','X'},{'X','O','O','X','O','O'},{'X','O','X','X','X','X'},{'O','O','X','O','X','X'},{'X','X','O','O','O','O'}};
	int m = 6, n = 6;

	vector<vector<char> > board;
	for (int i = 0; i < m; i++) {
		vector<char> b(n);
		for (int j = 0; j < n; j++) {
			b[j] = arr[i][j];
		}
		board.push_back(b);
	}
	display(board);

	Solution s = Solution();
	s.solve(board);
	display(board);

	return 0;
}