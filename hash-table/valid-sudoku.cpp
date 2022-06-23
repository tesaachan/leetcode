#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> hash_row;
        unordered_map<int, unordered_set<char>> hash_column;
        unordered_map<int, unordered_set<char>> hash_box;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == '.')
                    continue;
                if (hash_row[i].count(board[i][j])
                    || hash_column[j].count(board[i][j])) {
                    return false;
                }
                if (hash_box[(i / 3) * 10 + j / 3].count(board[i][j]))
                    return false;
                hash_row[i].insert(board[i][j]);
                hash_column[j].insert(board[i][j]);
                hash_box[(i / 3) * 10 + j / 3].insert(board[i][j]);
            }
        }
        return true;
    }
};