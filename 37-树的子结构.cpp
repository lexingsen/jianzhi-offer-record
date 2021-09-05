struct TreeNode {
    TreeNode* left;
    TreeNode* right;
    int val;
};


class Solution {
public:
    bool isPart(TreeNode* A, TreeNode* B) {
        // B的所有节点已经比完了，并且都能对应匹配  当B为nullptr时，直接返回false
        if (!B) {
            return true;
        }
        // 1.B不为nullptr, 但A已经nullptr了，说明B不是A的子结构
        // 2.A和B对应val值不同，直接返回false
        if (!A || A->val != B->val) {
            return false;
        }
        // 说明B不空、A不空 并且A->val == B->val  此时需要递归判断 A->left与B->left  A->right与B->right
        return isPart(A->left, B->left) && isPart(A->right, B->right);
    }
    bool hasSubtree(TreeNode* A, TreeNode* B) {
        if (!A || !B) {
            return false;
        }
        if (isPart(A, B)) {
            return true;
        }
        return hasSubtree(A->left, B) || hasSubtree(A->right, B);
    }
};