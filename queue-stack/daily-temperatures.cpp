// should be solved with DP
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer(temperatures.size(), 0);
        stack<pair<int,int>> st;
        for (int i = 0; i < temperatures.size(); i++) {
            while (!st.empty() && temperatures[st.top().first] < temperatures[i])
            {
                int val = st.top().second;
                answer[st.top().first] = st.top().second;
                st.pop();
                if (!st.empty())
                  st.top().second += val;
            }
            pair<int,int> p(i, 1);
            st.push(p);
        }
        return answer;
    }
};