#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



/*
全排列
(1) 不包含重复数字
(2) 包含重复数字
    同一个数字的相对位置不能发生变化
*/

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    

    // state：相当于一个位数组  位为1表示这个位置已经被占用  位为0表示这个位置没有被占用
    // u：当前要放置的数字的下标 nums[u]
    // start: 从数组的哪个下标开始放nums[u]
    void dfs(vector<int> nums, int u, int start, int state) {
        if (u == nums.size()) {
            ans.emplace_back(path);
            return;
        }
        // u==0 || 这次要放的数字和上一次放置的数字不同
        if (!u || nums[u] != nums[u-1]) {
            start = 0; // 那么就可以从0下标开始枚举
        }
        for (int i = start; i < nums.size(); i++) {
            if (!(state >> i & 1)) {
                path[i] = nums[u];
                dfs(nums, u + 1, i + 1, state + (1 << i));
            }
        }
    }

    vector<vector<int>> permutation(vector<int>& nums) {
        path.resize(nums.size());
        sort(nums.begin(), nums.end());
        dfs(nums, 0, 0, 0);
        return ans;
    }
};



void perm(vector<int>& nums, int p, int q) {
    if (p == q) {
        cout << "[";
        for_each(nums.begin(), nums.end(), [] (int x) {cout << x << " ";});
        cout << "]" << endl;
    }
    for (int i = p; i <= q; i++) {
        swap(nums[p], nums[i]);
        perm(nums, p + 1, q);
        swap(nums[p], nums[i]);
    }
}


int main() {
    vector<int> arr = {1, 2, 3};
    perm(arr, 0, arr.size() - 1);
    return 0;
}