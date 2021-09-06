
#include <vector>
#include <stack>
using namespace std;



class Solution {
public:
    bool isPopOrder(vector<int> pushV, vector<int> popV) {
        if (pushV.size() != popV.size()) {
            return false;
        }
        if (pushV.empty() && popV.empty()) {
            return true;
        }

        stack<int> stk;
        int idx = 0;
        for (auto x: pushV) {
            stk.push(x);
            while (!stk.empty() && stk.top() == popV[idx]) {
                stk.top();
                idx++;
            }
        }
        return stk.empty();
    }
};