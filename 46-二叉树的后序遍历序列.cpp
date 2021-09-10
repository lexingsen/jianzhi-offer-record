#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    vector<int> postOrder;

    // [4, 8, 6, 12, 16, 14, 10] 10 把整个区间分为 [4, 8, 6] 10 [12, 16, 14]
    //                                             [4] 6 [8]  [12] 14 [16]
    bool dfs(int l, int r) {
        if (l >= r) {
            return true;
        }
        int idx = l;
        int lastNumber = postOrder[r];
        while (idx < r && postOrder[idx] < lastNumber) {
            idx ++;
        }
        // 判断是否合法
        for (int i = idx; i < r; i++) {
            if (postOrder[i] < lastNumber) {
                return false;
            }
        }

        // 此时i指向12
        return dfs(l, idx - 1) && dfs(idx, r - 1);
        
    }

    bool verifySequenceOfBST(vector<int> sequence) {
        postOrder = sequence;
        return dfs(0, postOrder.size() - 1);
    }
};