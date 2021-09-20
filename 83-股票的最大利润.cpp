#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxDiff(vector<int>& nums) {
        int res = 0;
        for (int i = 0, minp = INT_MAX; i < nums.size(); i++) {
            res = max(res, nums[i] - minp);
            minp = min(minp, nums[i]);
        }
        return res;
    }
};