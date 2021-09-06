#include <stack>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        stk.push(x);
        if (stkMin.size()) {
            x = min(x, stkMin.top());
        }
        stkMin.push(x);
    }
    
    void pop() {
        stk.pop();
        stkMin.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return stkMin.top();
    }
private:
    stack<int> stk;
    stack<int> stkMin; // 前i个数中的最小值
};
