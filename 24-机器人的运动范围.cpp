#include <iostream>
#include <vector>

class Solution {
public:
    int get_sum(pair<int, int> p) {
        int s = 0;
        while (p.first) {
            s += (p.first % 10);
            p.first /= 10;
        }
        while (p.second) {
            s += (p.second % 10);
            p.second /= 10;
        }
        return s;
    }

    int movingCount(int threshold, int rows, int cols) {
        int res = 0;
        if (!rows || !cols) {
            return res;
        }
        vector<vector<bool>> st(rows, vector<bool>(cols, false));
        queue<pair<int, int>> q;
        q.push({0, 0});

        while (!q.empty()) {
            auto f = q.front();
            q.pop();
            if (get_sum(f) > threshold || st[f.first][f.second]) {
                continue;
            }
            res++;
            st[f.first][f.second] = true;
            int dx[4] = {0, 1, 0, -1};
            int dy[4] = {-1, 0, 1, 0};
            for (int i = 0; i < 4; i++) {
                int x = f.first + dx[i];
                int y = f.second + dy[i];
                if (x >= 0 && x < rows && y >= 0 && y < cols) {
                    q.push({x, y});
                }
            }
        }
        return res;
    }
};