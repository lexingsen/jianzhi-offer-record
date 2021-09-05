struct TreeNode {
    TreeNode* left;
    TreeNode* right;
    int val;
};


class Solution {
public:

    bool dfs(TreeNode* a, TreeNode* b) {
        // 两棵树都为空，一定对称
        if (!a && !b) {
            return true;
        }
        // 一棵树为空 一棵树不为空 直接返回false  一定不对称
        if ((!a && b) || (!b && a)) {
            return false;
        }
        // 当前两棵树的根节点的值不同 一定不对称
        if (a->val != b->val) {
            return false;
        }
        if (a->val == b->val) {
            // 当前两棵树根节点的值相同  同时满足a->left与b->right 对称    以及a->right和b->left对称
            return dfs(a->left, b->right) && dfs(a->right, b->left);
        }
    }
    bool isSymmetric(TreeNode* root) {
        // 空树直接返回true  空树就是一颗对称二叉树
        if (!root) {
            return true;
        }

        return dfs(root->left, root->right);
    }
};