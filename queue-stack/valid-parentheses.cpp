#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '[' || s[i] == '{' || s[i] == '(')
            {
                st.push(s[i]);
            }
            else if (st.size() > 0 && ((st.top() == '[' && s[i] == ']')
                || (st.top() == '{' && s[i] == '}')
                || (st.top() == '(' && s[i] == ')')))
            {
                st.pop();
            }
            else
                return false;
        }
        if (st.size() == 0)
            return true;
        return false;
    }
};