class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int n = rotateArray.size();
        if (!n) {
            return 0;
        }
        
        int l = 0, r = n - 1;
        while (l <= r-1) {
            if (rotateArray[l] < rotateArray[r]) {
                return rotateArray[l];
            }
            
            int mid = (l + r) / 2;
            if (rotateArray[mid] < rotateArray[l]) {
                r = mid;
            }
            else if (rotateArray[mid] > rotateArray[l]) {
                l = mid;
            }
    	    else {
                if (rotateArray[mid] < rotateArray[r]) {
                    r = mid;		
                }
                else l++;
            }
        }
        
        return min(rotateArray[l], rotateArray[r]);
    }
};