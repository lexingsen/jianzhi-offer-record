class Solution
{
public:
    int findMin(vector<int> &nums) {
        int n = nums.size() - 1; // n表示数组元素最后一个位置的下标·
        if (n < 0) {
            return -1;
        }
        // 去重相同的重复元素
        while (n > 0 && nums[n] == nums[0]) {
            n--;
        }
        // [1,1,1,1,1]
        if (nums[n] >= nums[0]) {
            return nums[0];
        }

        int l = 0;
        int r = n;
        while (l < r) {
            int m = l + r >> 1;
            if (nums[m] < nums[0]) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return nums[l];
    }
};
