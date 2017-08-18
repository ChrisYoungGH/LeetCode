class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string keyboard[3] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        map<char, int> keyMap;
        for (int i = 0; i < 3; i++) {
            for (char c : keyboard[i]) {
                keyMap[c] = i;
            }
        }

        vector<string> ans;
        for (string word : words) {
            string lowerWord = word;
            transform(lowerWord.begin(), lowerWord.end(), lowerWord.begin(), ::tolower);
            int flag = keyMap[lowerWord[0]];
            for (char c : lowerWord) {
                if (keyMap[c] != flag) {
                    flag = -1;
                    break;
                }
            }

            if (flag != -1) {
                ans.push_back(word);
            }
        }

        return ans;
    }
};
