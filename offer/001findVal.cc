class Solution {
public:
    bool Find(int target, vector<vector<int> >& array) {
        int m = array.size();
        if (m == 0) {
            return false;
        }
    
        int n = array[0].size();
        if (n == 0) {
            return false;
        }
    
        int i = 0, j = n - 1;
    
        while (i < n && j >= 0) {
            if (array[i][j] == target) {
                return true;
            }
            
            if (array[i][j] > target) {
                j--;
            }
            else {
                i++;
            }
        }
    
        return false;
    }
};
