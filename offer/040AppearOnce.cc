class Solution {
public:
    void FindNumsAppearOnce(vector<int> &data,int* num1,int *num2) {
    	int n = data.size();
    	if (!n) {
    		return;
    	}

    	int xorSum = getXorSum(data);
    	int index = indexOfFirstBit1(xorSum);

    	vector<vector<int> > subData(2);
    	for (int i = 0; i < n; i++) {
    		subData[isBit1(data[i], index)].push_back(data[i]);
    	}

    	*num1 = getXorSum(subData[0]);
    	*num2 = getXorSum(subData[1]);
    }

    int getXorSum(vector<int> &data) {
    	int xorSum = 0;
    	for (int i = 0; i < data.size(); i++) {
    		xorSum ^= data[i];
    	}
    	return xorSum;
    }

    int indexOfFirstBit1(int x) {
    	for (int i = 0; i < sizeof(int) * 8; i++) {
    		int bit = x & 0x1;
    		if (bit) {
    			return i;
    		}
    		x >>= 1;
    	}
    	return 0;
    }

    int isBit1(int x, int index) {
    	return ((x >> index) & 0x1);
    }
};