#include <unordered_map>
#include <vector>
#include <string>
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
    unordered_map<string, TreeNode*> hashmap;
    unordered_map<string, TreeNode*> answer;

    string find(TreeNode *root) {
        if (!root)
            return "-";

        string cur = to_string(root->val);
        string left = find(root->left);
        string right = find(root->right);
        if (left == "-") left = "->";
        if (right == "-") right = "<-";

        string result = left + cur + right;
        if (hashmap.count(result) && !answer.count(result)) {
            answer[result] = root;
        }
        hashmap[result] = root;
        return result;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        find(root);
        vector<TreeNode*> ans_to_vec;
        for (auto it = answer.begin(); it != answer.end(); it++) {
            ans_to_vec.push_back(it->second);
        }
        return ans_to_vec;
    }
};