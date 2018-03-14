class Solution {
public:
    bool judgeCircle(string moves) {
        map<char,int> counts;
        for (char c : moves) {
            counts[c]++;
        }

        if (counts['U'] == counts['D'] && counts['L'] == counts['R']) {
            return true;
        }
        return false;
    }
};
