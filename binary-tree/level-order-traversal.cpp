#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
            return {};
        vector<vector<int>> ans = {{}};
        queue<pair<TreeNode *, int>> nodes;
        nodes.push(make_pair(root, 0));
        while (!nodes.empty())
        {
            pair<TreeNode *, int> cur = nodes.front();
            if (cur.second > ans.size() - 1)
                ans.push_back({});
            ans[cur.second].push_back(cur.first->val);
            if (cur.first->left)
                nodes.push(make_pair(cur.first->left, cur.second + 1));
            if (cur.first->right)
                nodes.push(make_pair(cur.first->right, cur.second + 1));
            nodes.pop();
        }
        return ans;
    }
};