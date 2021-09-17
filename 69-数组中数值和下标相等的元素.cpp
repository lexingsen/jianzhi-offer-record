class Solution {
public:
    int getNumberSameAsIndex(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            int m = (r - l) / 2 + l;
            if (nums[m] == m) {
                return nums[m];
            } else if (nums[m] < m) {
                l++;
            } else {
                r--;
            }
        }
        return -1;
    }
};