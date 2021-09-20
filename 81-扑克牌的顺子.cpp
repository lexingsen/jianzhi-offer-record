#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isContinuous(vector<int> nums) {
        if (!nums.size()) {
            return false;
        }
        // 排序
        sort(nums.begin(), nums.end());
        // 去除0
        int k = 0;
        while (!nums[k]) {
            k++;
        }
        for (int i = k + 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1]) {
                return false;
            }
        }
        return nums.back() - nums[k] <= 4;
    }
};