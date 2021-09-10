#include <vector>
#include <iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

using pnn = pair<TreeNode*, TreeNode*>;

using pnn = pair<TreeNode*, TreeNode*>;

class Solution {
public:
    pnn dfs(TreeNode* root) {
        if (!root->left && !root->right) {
            return {root, root};
        }
        if (root->left && root->right) {
            auto lsides = dfs(root->left);
            auto rsides = dfs(root->right);
            lsides.second->right = root;
            root->left = lsides.second;
            root->right = rsides.first;
            rsides.first->left = root;
            
            return {lsides.first, rsides.second};
        }
        if (!root->left && root->right) {
            auto rsides = dfs(root->right);
            root->right = rsides.first;
            rsides.first->left = root;
            return {root, rsides.second};
        }
        if (root->left && !root->right) {
            auto lsides = dfs(root->left);
            lsides.second->right = root;
            root->left = lsides.second;
            return {lsides.first, root};
        }
    }


    TreeNode* convert(TreeNode* root) {
        if (!root) {
            return nullptr;
        }
        pnn res = dfs(root);
        return res.first;
    }
};