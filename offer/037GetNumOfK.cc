#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int GetNumberOfK(vector<int> &data ,int k) {
        int n = data.size();
        if (!n) {
        	return 0;
        }

        int low = lower_bound(data, k);
        int up = upper_bound(data, k);

        return (low > -1 && up < n) ? up - low + 1 : 0;
    }


    int lower_bound(vector<int> &data, int k) {
    	int n = data.size();
    	int low = 0, high = n - 1;
    	while (low < high) {
    		int mid = (low + high) / 2;
    		if (data[mid] < k) {
    			low = mid + 1;
    		}
    		else if (data[mid] > k) {
    			high = mid - 1;
    		}
    		else {
    			if (mid == 0 || data[mid-1] != k) {
    				return mid;
    			}
    			else {
    				high = mid - 1;
    			}
    		}
    	}
    	return data[low] == k ? low : -1;
    }


    int upper_bound(vector<int> &data, int k) {
    	int n = data.size();
    	int low = 0, high = n - 1;
    	while (low < high) {
    		int mid = (low + high) / 2;
    		if (data[mid] < k) {
    			low = mid + 1;
    		}
    		else if (data[mid] > k) {
    			high = mid - 1;
    		}
    		else {
    			if (mid == n-1 || data[mid+1] != k) {
    				return mid;
    			}
    			else {
    				low = mid + 1;
    			}
    		}
    	}
    	return data[high] == k ? high : n;
    }
};

int main() {
	Solution s = Solution();
	vector<int> arr = {2,2,2,2,2};
	cout << s.GetNumberOfK(arr, 1) << endl;
	return 0;
}