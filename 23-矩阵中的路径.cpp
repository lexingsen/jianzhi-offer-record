class Solution {
public:
    bool hasPath(vector<vector<char>> &matrix, string &str) {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (dfs(matrix, str, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>> &matrix, string &str, int cur, int x, int y) {
        if (matrix[x][y] != str[cur]) {
            return false;
        }
        if (cur == str.size() - 1){
            return true;
        }

        char t = matrix[x][y];
        matrix[x][y] = '*';
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int a = dx[i] + x;
            int b = dy[i] + y;
            if (a >= 0 && a < matrix.size() && b >= 0 && b < matrix[a].size()) {
                if (dfs(matrix, str, cur + 1, a, b)) {
                    return true;
                }
            }
        }
        matrix[x][y] = t;
        return false;
    }
};
