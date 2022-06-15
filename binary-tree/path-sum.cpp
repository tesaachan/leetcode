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
    int targetSum;
    bool ans = false;
    void traverse(TreeNode *root, int curSum) {
        if (ans == true)
            return;
        if (!root->left && !root->right) {
            if (curSum == targetSum)
                ans = true;
            return;
        }
        if (root->left)
            traverse(root->left, curSum + root->left->val);
        if (root->right)
            traverse(root->right, curSum + root->right->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root)
            return false;
        this->targetSum = targetSum;
        traverse(root, root->val);
        return ans;
    }
};