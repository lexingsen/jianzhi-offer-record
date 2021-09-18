#include <vector>
using namespace std;


// [1,2,3,3,4,4] -> [1,2]
/*
1.异或所有数字  得到x^y=s
2.设s的第k位为1    将原来的集合分为第k位为0和第k位为1   x和y一定是一个集合中有一个
3.各自异或后，剩下的就分别是x和y
*/
class Solution {
public:
    vector<int> findNumsAppearOnce(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum ^= nums[i];
        }
        int k = 0;
        while (!(sum >> k & 1)) {
            k++;
        }
        
        int first = 0;
        for (auto x: nums) {
            if ((x >> k & 1) == 1) {
                first ^= x;
            }
        }
        return {first, sum ^ first};
    }
};