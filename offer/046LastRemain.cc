#include <iostream>
#include <list>

using namespace std;

class Solution {
public:
    int LastRemaining_Solution(int n, int m) {
    	if (n < 1 || m < 1) {
    		return -1;
    	}

        list<int> circle;
        for (int i = 0; i < n; i++) {
        	circle.push_back(i);
        }

        list<int>::iterator curr = circle.begin(), next;

        while (circle.size() > 1) {
        	for (int i = 1; i < m; i++) {
        		++curr;
        		if (curr == circle.end()) {
        			curr = circle.begin();
        		}
        	}

        	next = ++curr;
        	if (next == circle.end()) {
        		next = circle.begin();
        	}

        	circle.erase(--curr);
        	curr = next;
        }

        return *curr;
    }

    int LastRemaining_Solution2(int n, int m) {
    	if (n < 1 || m < 1) {
    		return -1;
    	}

    	int last = 0;
    	for (int i = 2; i <= n; i++) {
    		last = (last + m) % i;
    	}

    	return last;
    }
};

int main() {
	Solution s = Solution();
	cout << s.LastRemaining_Solution2(4, 2) << endl;
}