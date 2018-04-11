class Solution {
public:
	int FirstNotRepeatingChar(string str) {
		int n = str.length();
		if (!n) {
			return -1;
		}

		int chars[256] = {0};
		for (int i = 0; i < n; i++) {
			chars[str[i]]++;
		}

		for (int i = 0; i < n; i++) {
			if (chars[str[i]] == 1) {
				return i;
			}
		}

		return -1;
	}
};