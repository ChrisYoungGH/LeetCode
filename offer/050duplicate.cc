#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if (!numbers || !length) {
        	return false;
        }

        set<int> count;
        for (int i = 0; i < length; i++) {
        	if (count.find(numbers[i]) == count.end()) {
        		count.insert(numbers[i]);
        	}
        	else {
        		*duplication = numbers[i];
        		return true;
        	}
        }

        return false;
    }
};

int main() {
	Solution s = Solution();
	int numbers[] = {2,3,1,0,2,5,3};
	int length = sizeof(numbers) / sizeof(int);
	int duplication;
	bool status = s.duplicate(numbers, length, &duplication);
	if (status) {
		cout << duplication << endl;
	}
	else {
		cout << "Invalid" << endl;
	}

	return 0;
}