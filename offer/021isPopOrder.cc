class Solution {
public:
	bool IsPopOrder(vector<int> &pushV, vector<int> &popV) {
		int nPush = pushV.size(), nPop = popV.size();
		if (!nPush || !nPop || nPush != nPop) {
			return false;
		}

		int currPush = 0, currPop = 0;
		stack<int> s;

		while (currPop < nPop) {
			while (s.empty() || s.top() != popV[currPop]) {
				if (currPush >= nPush) {
					return false;
				}
				s.push(pushV[currPush++]);
			}

			s.pop();
			currPop++;
		}

		return true;
	}
};