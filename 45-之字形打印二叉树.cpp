#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<vector<int>> printFromTopToBottom(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        bool zigzag = true; // 从第二层开始
        int level = 0;
        while (q.size()) {
            int n = q.size();
            vector<int> row;
            while (n--) {
                auto f = q.front(); q.pop();
                row.emplace_back(f->val);
                if (f->left) {
                    q.push(f->left);
                }
                if (f->right) {
                    q.push(f->right);
                }
            }
            level++;
            if (zigzag && level>=2) {
                reverse(row.begin(), row.end());
                zigzag = false;
            } else {
                zigzag = true;
            }
            res.emplace_back(row);
            row.clear();
        }


        return res;
    }
};
