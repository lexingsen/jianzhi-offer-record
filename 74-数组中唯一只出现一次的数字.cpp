#include <vector>
using namespace std;


// [1,1,1,2,2,2,3,4,4,4]->[3]

// 常规做法
class Solution {
public:
    int findNumberAppearingOnce(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            // 统计1出现的次数
            int cnt = 0;
            for (auto x: nums) {
                if (x >> i & 1) {
                    cnt ++;
                }
            }
            if (cnt % 3 == 1) {
                ans |= 1 << i;
            }
        }
        return ans;
    }
};


// 进阶做法 位运算  状态机
class Solution {
public:
    int findNumberAppearingOnce(vector<int>& nums) {
        
    }
};