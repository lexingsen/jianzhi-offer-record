
struct TreeNode {
    TreeNode* left;
    TreeNode* right;
    int val;
};


class Solution {
public:
    void swap(TreeNode* &a, TreeNode* &b) {
        TreeNode* p = a;
        a = b;
        b = p;
    }
    void dfs(TreeNode* root) {
        if (!root) {
            return;
        }
        // 不是空树，交换当前树的左右子树
        swap(root->left, root->right);
        // 递归处理左子树
        dfs(root->left);
        // 递归处理右子树
        dfs(root->right);
    }

    void mirror(TreeNode* root) {
        dfs(root);
    }
};
