class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n) {
    	if (n <= 0) {
    		return 0;
    	}

    	char strN[50];
    	sprintf(strN, "%d", n);

    	return NumberOf1(strN);
    }

    int NumberOf1(char *strN) {
    	if (!strN || strN[0] == '\0' || strN[0] < '0' || strN[0] > '9') {
    		return 0;
    	}

    	int first = strN[0] - '0';
    	int len = strlen(strN);
    	if (len == 1) {
    		return first > 0;
    	}

    	int numFirstDigit = 0;
    	if (first > 1) {
    		numFirstDigit = pow(10, len - 1);
    	}
    	else if (first == 1) {
    		numFirstDigit = atoi(strN + 1) + 1;
    	}

    	int numOtherDigits = first * (len - 1) * pow(10, len - 2);

    	int numRemoveFirst = NumberOf1(strN + 1);

    	return numFirstDigit + numOtherDigits + numRemoveFirst;
    }
};