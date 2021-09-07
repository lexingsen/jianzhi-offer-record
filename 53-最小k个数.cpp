#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> getLeastNumbers_Solution(vector<int> input, int k) {
        if (!input.size() || !k) {
            return {};
        }
        vector<int> res;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < input.size(); i++) {
            pq.push(input[i]);
        }
        
        while (k--) {
            res.emplace_back(pq.top());
            pq.pop();
        }
        
        sort(res.begin(), res.end());
        return res;
    }
};