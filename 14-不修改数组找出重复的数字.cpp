class Solution {
public:
    int duplicateInArray(vector<int>& nums) {
        int l = 1;
        int r = nums.size() - 1;  // 长度为n+1   区间的下标的是数值
        while (l < r) {
            int m = l + r >> 1;
            int cnt = 0;
            for (auto x:nums) {
                if (x >= l && x <= m) {
                    cnt ++;
                }
            }
            if (cnt > m - l + 1) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return r;
    }
};