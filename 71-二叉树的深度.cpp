class Solution {
public:
    int treeDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return max(treeDepth(root->left), treeDepth(root->right)) + 1;
    }
};