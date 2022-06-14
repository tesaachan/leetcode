#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    int f(int i, int j) {
        if (j == 0 || j == i)
            return 1;
        if (dp[i][j] != 0)
            return dp[i][j];
        dp[i][j] = f(i - 1, j) + f(i - 1, j - 1);
        return dp[i][j];
    }
    vector<int> getRow(int rowIndex) {
        dp.resize(rowIndex + 1, vector<int>(rowIndex + 1, 0));
        vector<int> pascalRow;
        for (int i = 0; i < rowIndex + 1; i++) {
            pascalRow.push_back(f(rowIndex, i));
        }
        return pascalRow;
    }
};