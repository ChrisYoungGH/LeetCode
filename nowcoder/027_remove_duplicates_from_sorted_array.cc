class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int nUniques = 0;
        int i = 0;
        while (i < n) {
        	if (!i || A[i] != A[i-1]) {
        		A[nUniques++] = A[i];
        	}
        	i++;
        }
        return nUniques;
    }
};