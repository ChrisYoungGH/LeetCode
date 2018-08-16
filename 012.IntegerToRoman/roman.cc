#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int base[7] = {1,5,10,50,100,500,1000};
map<int, char> name = {{1,'I'}, {5,'V'}, {10,'X'}, {50,'L'}, {100,'C'}, {500,'D'}, {1000,'M'}};

string intToRoman(int num) {
	// count number of each base
	map<int, int> baseCount;
	for (int i = 6; i >= 0; i--) {
		int b = base[i];
		baseCount[b] = num / b;
		num %= b;
	}

	// up and add (only {-1,0,1,2,3} or {0,1})
	for (int i = 4; i >= 0; i -= 2) {
		int baseCurr = base[i];
		int basePrev = base[i+1];
		int basePrevPrev = base[i+2];

		if (baseCount[baseCurr] == 4) {
			baseCount[baseCurr] = -1;
			baseCount[basePrev]++;
		}

		if (baseCount[basePrev] == 2) {
			baseCount[basePrev] = 0;
			baseCount[basePrevPrev]++;
		}
	}

	// write from right to left
	string result = "";
	for (int i = 6; i >= 0; i--) {
		int baseCurr = base[i];
		int basePrev = i < 6 ? base[i+1] : 1;
		int basePrevPrev = i < 5 ? base[i+2] : 1;

		// find the highest place that has zero value
		if (baseCount[baseCurr] < 0) {
			int j = i;
			while (j+1 < 7 && baseCount[base[j+1]] == 0) {
				j++;
			}
			j -= j % 2;
			// insert into left first
			result = result.substr(0, int(result.length())-1) + name[base[j]] + result[int(result.length())-1];
			// append on right
			for (int k = j; k >= i + 2; k -= 2) {
				result = result + name[base[k-2]] + name[base[k]];
			}
		}
		
		// normally write (letter * times)
		else {
			for (int j = 0; j < baseCount[baseCurr]; j++) {
				result = result + name[baseCurr];
			}
		}
	}

	return result;
}

int main() {
	for (int i = 1; i <= 3999; i++) {
		cout << i << ": " << intToRoman(i) << endl;
	}
	return 0;
}