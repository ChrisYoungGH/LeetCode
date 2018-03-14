class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        map<char,int> letters;
        for (char c : p) {
            letters[c]++;
        }

        int left = 0, right = 0;
        int count = 0;
        vector<int> ans;

        while (right < s.size()) {
            char c = s[right];
            if (letters.find(c) != letters.end()) {
                letters[c]--;
                if (letters[c] >= 0) {
                    count++;
                }
            }
            right++;

            if (count == p.size()) {
                ans.push_back(left);
            }

            if (right - left == p.size()) {
                char c = s[left];
                if (letters.find(c) != letters.end()) {
                    letters[c]++;
                    if (letters[c] > 0) {
                        count--;
                    }
                }
                left++;
            }
        }

        return ans;
    }
};
