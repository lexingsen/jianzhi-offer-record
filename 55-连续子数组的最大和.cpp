#include <vector>
using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int last = nums[0];
        int res = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int now = max(last, 0) + nums[i];
            res = max(res, now);
            last = now;
        }

        return res;
    }
}