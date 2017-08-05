#include <iostream>
#include <string>
#include <stack>
#include <set>
#include <map>

using namespace std;

class Solution {
public:

    // 每个右括号都要与当前栈顶匹配，否则为非法
    bool isValid(string s) {
        set<char> left, right;
        left.insert('('); left.insert('['), left.insert('{');
        right.insert(')'); right.insert(']'), right.insert('}');

        map<char, char> par;
        par['('] = ')';
        par['['] = ']';
        par['{'] = '}';

        stack<char> st;

        for (unsigned int i = 0; i < s.size(); i++) {
            char c = s[i];
            set<char>::iterator leftIt = left.find(c);
            set<char>::iterator rightIt = right.find(c);
            if (leftIt != left.end()) {
                st.push(c);
            }
            else if (rightIt != left.end()) {
                if (!st.empty() && par[st.top()] == c) {
                    st.pop();
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }

        return st.empty();
    }
};

int main(int argc, char const *argv[]) {
    Solution s = Solution();
    string str = "([]";
    cout << s.isValid(str);
    return 0;
}
