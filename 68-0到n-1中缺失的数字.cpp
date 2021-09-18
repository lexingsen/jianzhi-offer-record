#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int getMissingNumber(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            int m = l + r >> 1;
            if (nums[m] != m) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        if (nums[r] == r) {
            r++;
        }
        return r;
    }
};