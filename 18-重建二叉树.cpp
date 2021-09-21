class Solution {
public:
    map<int, int> hash;
    TreeNode *dfs(vector<int> &preorder, vector<int> &inorder, int pl, int pr, int il, int ir) {
        if (pl > pr)
        {
            return nullptr;
        }
        auto rt = preorder[pl];
        int index = hash[rt];

        TreeNode *root = new TreeNode(rt);
        int len = index - il;
        root->left = dfs(preorder, inorder, pl + 1, pl + len, il, index - 1);
        root->right = dfs(preorder, inorder, pl + len + 1, pr, index + 1, ir);
        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            hash[inorder[i]] = i;
        }
        return dfs(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};
