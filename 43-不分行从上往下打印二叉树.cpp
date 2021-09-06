#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    TreeNode* left;
    TreeNode* right;
    int val;
};

class Solution {
public:
    vector<int> printFromTopToBottom(TreeNode* root) {
        if (!root) {
            return {};
        }
        queue<TreeNode*> q;
        vector<int> res;
        q.push(root);
        while (!q.empty()) {
            auto f = q.front(); q.pop();
            res.emplace_back(f->val);
            if (f->left) {
                q.emplace(f->left);
            }
            if (f->right) {
                q.emplace(f->right);
            }
        }
        return  res;
    }
};