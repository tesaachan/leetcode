#include <vector>
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
    vector<int> preorder;
    void traversal(TreeNode* root) {
        if (!root)
            return;
        preorder.push_back(root->val);
        traversal(root->left);
        traversal(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root)
            return preorder;
        traversal(root);
        return preorder;
    }
};