class Solution {
public:
    void replaceSpace(char *str, int length) {
        if (!str || length == 0) {
            return;
        }
        
        int nSpaces = 0;
        for (int i = 0; i < length; i++) {
            if (str[i] == ' ') {
                nSpaces++;
            }
        }
        
        if (!nSpaces) {
            return;
        }
        
        int newLength = length + nSpaces * 2;

        int pNew = newLength - 1;
        
        for (int i = length - 1; i >= 0; i--) {
            if (str[i] != ' ') {
                str[pNew--] = str[i];
            }
            else {
                str[pNew--] = '0';
                str[pNew--] = '2';
                str[pNew--] = '%';
            }
        }
    }
};