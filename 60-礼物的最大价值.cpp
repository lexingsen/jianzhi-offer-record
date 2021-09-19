#include <vector>
#include <iostream>
using namespace std;


/*
转移方程: f[i][j] = max(f[i-1][j], f[i][j-1]) + grid[i][j]
表示从左上角f[0][0]到第i行第j列礼物的最大价值为，从左边f[i][j-1] 和 从上边f[i-1][j]走过来的最大值加上当前位置的礼物价值
*/

class Solution {
public:
    int getMaxValue(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int f[m][n] = {{ 0 }};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << f[i][j] << endl;
            }
        }
        // base case
        f[0][0] = grid[0][0];
        for (int i = 1; i < m; i++) {
            f[i][0] = f[i-1][0] + grid[i][0];
        }
        for (int j = 1; j < n; j++) {
            f[0][j] = f[0][j-1] + grid[0][j];
        }
        // base case end
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                f[i][j] = max(f[i-1][j], f[i][j-1]) + grid[i][j];
            }
        }
        
        return f[m-1][n-1];
    }
};