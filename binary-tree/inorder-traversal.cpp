#include <vector>
#include <stack>
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
    vector<int> inorder;
    void traverse(TreeNode *root) {
        if (!root)
            return;
        traverse(root->left);
        inorder.push_back(root->val);
        traverse(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        traverse(root);
        return inorder;
    }
};