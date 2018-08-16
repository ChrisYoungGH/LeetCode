#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    void initMap(map<char, string> &digitMap) {
        digitMap['0'] = "";
        digitMap['1'] = "";
        digitMap['2'] = "abc";
        digitMap['3'] = "def";
        digitMap['4'] = "ghi";
        digitMap['5'] = "jkl";
        digitMap['6'] = "mno";
        digitMap['7'] = "pqrs";
        digitMap['8'] = "tuv";
        digitMap['9'] = "wxyz";
    }

    void getCombinations(string &digits, map<char,string> &digitMap, 
                                   int index, vector<string> &prevComb,
                                   vector<string> &currComb) {

        char currDigit = digits[index];
        string currChars = digitMap[currDigit];

        if (currChars.length() == 0) {
            currComb = prevComb;
            return;
        }

        for (int i = 0; i < prevComb.size(); i++) {
            for (int j = 0; j < currChars.length(); j++) {
                    currComb.push_back(prevComb[i] + currChars.substr(j, 1));
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        map<char, string> digitMap;
        initMap(digitMap);

        vector<string> prevComb, currComb;
        if (digits.length() == 0) {
            return currComb;
        }

        currComb.push_back("");

        for (int i = 0; i < digits.length(); i++) {
            prevComb = currComb;
            currComb.clear();
            getCombinations(digits, digitMap, i, prevComb, currComb);
        }

        if (currComb.size() == 1 && currComb[0] == "") {
            currComb.clear();
        }

        return currComb;
    }
};