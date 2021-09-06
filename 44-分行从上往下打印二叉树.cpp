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
    vector<vector<int>> printFromTopToBottom(TreeNode* root) {
        if (!root) {
            return {};
        }
        queue<TreeNode*> q;
        vector<vector<int>> res;
        q.push(root);
        while (q.size()) {
            int n = q.size();
            vector<int> row;
            while (n--) {
                auto f = q.front(); q.pop();
                row.emplace_back(f->val);
                if (f->left) {
                    q.emplace(f->left);
                }
                if (f->right) {
                    q.emplace(f->right);
                }
            }
            res.emplace_back(row);
            row.clear();
        }
        return res;
    }
};