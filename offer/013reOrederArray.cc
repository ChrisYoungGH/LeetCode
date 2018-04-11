class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<vector<int> > evenOrOdd(2);
        for (int i = 0; i < array.size(); i++) {
            evenOrOdd[array[i] & 0x1].push_back(array[i]);
        }
        
        int m = 0;
        for (int k = 1; k >= 0; k--) {
            for (int i = 0; i < evenOrOdd[k].size(); i++) {
                array[m++] = evenOrOdd[k][i];
            }
        }
    }
};