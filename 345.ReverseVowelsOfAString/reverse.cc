class Solution {
public:
    string reverseVowels(string s) {
        set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
        vector<int> index;
        for (int i = 0; i < int(s.length()); i++) {
            if (vowels.find(s[i]) != vowels.end()) {
                index.push_back(i);
            }
        }

        for (int i = 0; i < int(index.size()); i++) {
            int left = index[i];
            int right = index[int(index.size()) - i - 1];
            char tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
        }

        return s;
    }
};
