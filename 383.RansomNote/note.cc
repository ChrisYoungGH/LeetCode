class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> letterCount;
        for (char c : magazine) {
            letterCount[c]++;
        }

        for (char c : ransomNote) {
            if (letterCount[c] <= 0) {
                return false;
            }
            letterCount[c]--;
        }

        return true;
    }
};
