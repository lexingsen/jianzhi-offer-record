class Solution {
public:
    TreeNode *inorderSuccessor(TreeNode *p) {
        if (p->right) {
            p = p->right;
            while (p->left) {
                p = p->left;
            }
            return p;
        }

        while (p->father && p->father->right == p) {
            p = p->father;
        }
        return p->father;
    }
};