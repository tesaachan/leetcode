#include <stack>
#include <set>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        set<string> operators = {"+","-","*","/"};
        stack<int> answer;
        for (int i = 0; i < tokens.size(); i++) {
            if (operators.find(tokens[i]) != operators.end())
            {
                int a = answer.top();
                answer.pop();
                if (tokens[i] == "+")
                    answer.top() += a;
                else if (tokens[i] == "-")
                    answer.top() -= a;
                else if (tokens[i] == "*")
                    answer.top() *= a;
                else
                    answer.top() /= a;
            } else {
                answer.push(stoi(tokens[i]));
            }
        }
        return answer.top();
    }
};