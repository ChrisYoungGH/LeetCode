#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> &arr, int sum) {
    	vector<int> res;

    	int n = arr.size();
    	if (n < 2) {
    		return res;
    	}

    	int low = 0, high = n - 1;
    	while (low < high) {
    		int currSum = arr[low] + arr[high];
    		if (currSum == sum) {
    			res.push_back(arr[low]);
    			res.push_back(arr[high]);
    			break;
    		}

    		else if (currSum < sum) {
    			low++;
    		}
    		else {
    			high--;
    		}
    	}

    	return res;
    }
};

int main() {
	Solution s = Solution();
	vector<int> arr = {1,2,4,7,11,16};
	vector<int> res = s.FindNumbersWithSum(arr, 10);
	cout << res[0] << " " << res[1] << endl;
}