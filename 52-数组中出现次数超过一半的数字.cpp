#include <vector>
using namespace std;





class Solution {
public:
    int moreThanHalfNum_Solution(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int val = nums[0];
        int cnt = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (val == nums[i]) {
                cnt++;
            } else {
                cnt--;
                if (cnt < 0) {
                    val = nums[i];
                    cnt = 1;
                }
            }
        }
        return val;
    }
};