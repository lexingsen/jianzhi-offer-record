#include <vector>
using namespace std;
struct TreeNode {
    TreeNode* left;
    TreeNode* right;
    int val;
};


class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<vector<int>> findPath(TreeNode* root, int sum) {
        if (!root) {
            return ans;
        }
        dfs(root, sum);
        return ans;
    }


    void dfs(TreeNode* root, int sum) {
        if (!root) {
            return;
        }
        sum -= root->val;
        path.emplace_back(root->val);
        if (root->left) {
            dfs(root->left, sum);
        }
        if (root->right) {
            dfs(root->right, sum);
        }
        path.pop_back();
    }
};