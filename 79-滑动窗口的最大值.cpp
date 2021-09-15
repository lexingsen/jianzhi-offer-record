#include <vector>
#include <queue>
#include <climits>
using namespace std;


class Solution {
public:
    vector<int> maxInWindows(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> q;
        for (int i = 0; i < nums.size(); i++) {
            // [2, 3, 4, 2, 6, 2, 5, 1]
            // q:[0, 1, 2]
            if (q.size() && q.front() <= i-k) {
                q.pop_front();
            }
            while (q.size() && nums[q.back()] <= nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
            if (i >= k-1) {
                ans.push_back(nums[q.front()]);
            }
        }
        return ans;
    }
};