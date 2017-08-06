#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> dict;
        dict['I'] = 1;
        dict['V'] = 5;
        dict['X'] = 10;
        dict['L'] = 50;
        dict['C'] = 100;
        dict['D'] = 500;
        dict['M'] = 1000;

        int sum = 0;
        for (int i = 0; i < int(s.size())-1; i++) {
            int curr = dict[s[i]];
            int next = dict[s[i+1]];
            if (curr < next) {
                sum -= curr;
            }
            else {
                sum += curr;
            }
        }

        return sum + dict[s[int(s.size())-1]];
    }
};

int main(int argc, char const *argv[]) {
    string s = "CMXCIX";
    Solution so = Solution();
    cout << so.romanToInt(s) << endl;
    return 0;
}
