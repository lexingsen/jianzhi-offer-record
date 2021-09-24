class Solution {
public:
    int duplicateInArray(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0 || nums[i] >= n) {
                return -1;
            }
        }
        for (int i = 0; i < n; i++) {
            while (nums[nums[i]] != nums[i]) {
                swap(nums[i], nums[nums[i]]);
            }
            if (i != nums[i]) {
                return nums[i];
            }

        }
        return -1;
    }
};
