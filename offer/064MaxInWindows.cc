#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
    	vector<int> res;
        if (!size) {
        	return res;
        }

        deque<int> max_index_q;

        for (int i = 0; i < num.size(); i++) {
        	while (!max_index_q.empty() && num[max_index_q.back()] <= num[i]) {
        		max_index_q.pop_back();
        	}
        	while (!max_index_q.empty() && i - max_index_q.front() + 1 > size) {
        		max_index_q.pop_front();
        	}
        	max_index_q.push_back(i);

        	if (i+1 >= size) {
        		res.push_back(num[max_index_q.front()]);
        	}
        }

        return res;
    }
};

int main() {
	Solution s = Solution();
	vector<int> arr = {2,3,4,2,6,2,5,1};
	vector<int> res = s.maxInWindows(arr, 3);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;
}