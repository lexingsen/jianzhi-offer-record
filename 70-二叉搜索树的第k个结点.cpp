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
    TreeNode* ans;
    void dfs(TreeNode* root, int& k) {
        if (!root) {
            return;
        }
        dfs(root->left, k);
        k--;
        if (!k) {
            ans = root;
        }
        if (k > 0) {
            dfs(root->right, k);   
        }
    }


    TreeNode* kthNode(TreeNode* root, int k) {
        dfs(root, k);
        return ans;
    }
};