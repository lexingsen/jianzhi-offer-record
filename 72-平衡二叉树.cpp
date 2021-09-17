#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class Solution {
public:

    int height(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return max(height(root->left), height(root->right)) + 1;
    }

    bool dfs(TreeNode* root) {
        if (!root) {
            return true;
        }
        if (abs(height(root->left) - height(root->right)) > 1) {
            return false;
        }
        bool left = dfs(root->left);
        bool right = dfs(root->right);
        return left && right;
    }

    bool isBalanced(TreeNode* root) {
        return dfs(root);
    }
};