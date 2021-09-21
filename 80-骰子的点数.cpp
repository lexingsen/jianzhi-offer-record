#include <iostream>
#include <vector>
using namespace std;

/*
dfs:
1.状态的表示
2.按照什么样的顺序搜索  dfs(n, sum) 掷n次色子，出现总和为sum的方案数

int dfs(int n, int sum) {
    if (sum < 0) {
        return 0;
    }
    if (n == 0) {
        return sum == 0;
    }
    int res = 0;
    // 最后一次掷出去的筛子点数为i
    for (int i = 1; i <= 6; i++) {
        res += dfs(n - 1, sum - i);
    }
    return sum;
}

vector<int> numberOfDice(int n) {
    vector<int> res;
    for (int i = n; i < 6 * n; i++) {
        res.push_back(dfs(i, n));
    }
    return res;
}
*/

/*
dp
状态表示
f[i][j]  前i次，总和为j的方案数

状态计算
将最后一次掷色子分为六个集合  点数分别1，2，3，4，5，6

边界

*/

class Solution {
public:
    vector<int> numberOfDice(int n) {
        vector<vector<int>> f(n + 1, vector<int>(6 * n + 1));
        f[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i * 6; j++) {
                for (int k = 1; k <= min(j, 6); ++k) {
                    f[i][j] += f[i-1][j-k];
                }
            }
        }
        vector<int> res;
        for (int i = n; i <= n * 6; i++) {
            res.push_back(f[n][i]);
        }
        return res;
    }
};