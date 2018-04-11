class Solution {
public:
    bool IsContinuous(vector<int> &numbers) {
    	int n = numbers.size();
    	if (n < 5) {
    		return false;
    	}

    	sort(numbers.begin(), numbers.end());

    	int nZeros = 0;
    	for (int i = 0; i < n; i++) {
    		if (numbers[i]) {
    			break;
    		}
    		nZeros++;
    	}

    	int nGaps = 0;
    	for (int i = nZeros+1; i < n; i++) {
    		if (numbers[i] == numbers[i-1]) {
    			return false;
    		}
    		nGaps += numbers[i] - numbers[i-1] - 1;
    	}

    	return nZeros >= nGaps;
    }
};