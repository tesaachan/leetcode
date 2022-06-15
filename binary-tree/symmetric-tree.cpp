// I don't like this solution. Try to solve it better
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
    vector<int> leftvec;
    vector<int> leftsteps;
    vector<int> rightvec;
    vector<int> rightsteps;
    int traverseLeft(TreeNode *root) {
        if (!root)
            return 0;
        int depth_left = 0;
        int depth_right = 0;
        leftvec.push_back(root->val);
        if (root->left) {
            leftsteps.push_back(0);
            depth_left = traverseLeft(root->left) + 1;
        }
        if (root->right) {
            leftsteps.push_back(1);
            depth_right = traverseLeft(root->right) + 1;
        }
        return max(depth_left, depth_right);
    }
    int traverseRight(TreeNode *root) {
        if (!root)
            return 0;
        int depth_left = 0;
        int depth_right = 0;
        rightvec.push_back(root->val);
        if (root->right) {
            rightsteps.push_back(0); 
            depth_right = traverseRight(root->right) + 1;
        }
        if (root->left) {
            rightsteps.push_back(1); 
            depth_left = traverseRight(root->left) + 1;
        }
        return max(depth_left, depth_right);
    }
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return false;
        if (!root->left && !root->right)
            return true;
        if (!root->left || !root->right)
            return false;

        if (traverseLeft(root->left) != traverseRight(root->right))
            return false;
        if (rightsteps.size() != leftsteps.size())
            return false;
        for (int i = 0; i < leftsteps.size(); i++) {
            if (leftsteps[i] != rightsteps[i])
                return false;
        }
        for (int i = 0; i < leftvec.size(); i++) {
            if (leftvec[i] != rightvec[i])
                return false;
        }
        return true;
    }
};