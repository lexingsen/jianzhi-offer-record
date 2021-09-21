/*
利用每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序这个性质
每次从每行的最后一个位置开始找
*/
class Solution {
public:
    bool searchArray(vector<vector<int>> array, int target) {
        if (!array.size()) {
            return false;
        }
        int n = array.size();
        int m = array[0].size();
        int row = 0;
        int col = m - 1;
        while (row >= 0 && row < n && col >= 0 && col < m) {
            if (array[row][col] == target) {
                return true;
            } else if (array[row][col] > target) {
                col--;
            } else {
                row++;
            }
        }
        return false;
    }
};