

struct TreeNode {
    TreeNode* left;
    TreeNode* right;
    int val;
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) {
            return nullptr;
        }

        if (p == root || q == root) {
            return root;
        }
        auto left = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);
        if (left && right) {
            return root;
        }
        if (left && !right) {
            return left;
        }
        if (right && !left) {
            return right;
        }
    }
};