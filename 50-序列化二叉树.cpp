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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        dfs1(root, res);
        return res;
    }

    

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int u = 0;
        return dfs2(data, u);
    }

    void dfs1(TreeNode* root, string& res) {
        if (!root) {
            res += "null ";
            return ;
        }
        res += to_string(root->val) + ' ';
        dfs1(root->left, res);
        dfs1(root->right, res);
    }

    TreeNode* dfs2(string data, int& u) {
        if (u == data.size()) {
            return nullptr;
        }
        int k = u;
        while (data[k] != ' ') {
            k++;
        }
        if (data[u] == 'n') {
            u = k+1;
            return nullptr;
        }
        bool is_neg = false;
        if (data[u] == '-') {
            is_neg = true;
            u++;
        }
        int x = 0;
        for (int i = u; i < k; i++) {
            x = x * 10 + data[i] - '0';
        }
        if (is_neg) {
            x = -x;
        }
        u = k + 1;
        TreeNode* root = new TreeNode(x);
        root->left = dfs2(data, u);
        root->right = dfs2(data, u);
        return root;
    }
};