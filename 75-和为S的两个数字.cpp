#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findNumbersWithSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        // 单调性
        int l = 0;
        int r = nums.size();

        while (l < r) {
            int x = nums[l] + nums[r];
            if (x < target) {
                l++;
            } else if (x > target) {
                r--;
            } else {
                return {nums[l], nums[r]};
            }
        }
        return {};
    }
};