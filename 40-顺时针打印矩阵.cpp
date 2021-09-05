#include <vector>
using namespace std;



class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int n = matrix.size();
        if (!n) {
            return {};
        }
        int m = matrix[0].size();
        vector<int> res;
        vector<vector<bool>> st(n, vector<bool>(m, false));
        int dy[] = {0, 1, 0, -1};
        int dx[] = {-1, 0, 1, 0};
        int x = 0, y = 0;
        int d = 1;
        for (int i = 0; i < n * m; i++) {
            res.emplace_back(matrix[x][y]);
            st[x][y] = true;
            int a = x + dx[d];
            int b = y + dy[d];
            if (a < 0 || a >= n || b < 0 || b >= m || st[a][b]) {
                d = (d + 1) % 4;
                a = x + dx[d];
                b = y + dy[d];
            }
            x = a, y = b;
        }
        return res;
    }
};