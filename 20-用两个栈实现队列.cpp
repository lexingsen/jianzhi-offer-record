class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {}

    /** Push element x to the back of queue. */
    void push(int x) {
        data.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        reverse(data, aux);
        int res = aux.top();
        aux.pop();
        reverse(aux, data);
        return res;
    }

    /** Get the front element. */
    int peek() {
        reverse(data, aux);
        int res = aux.top();
        reverse(aux, data);
        return res;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return data.empty();
    }

    void reverse(stack<int> &data, stack<int> &aux) {
        while (!data.empty()) {
            aux.push(data.top());
            data.pop();
        }
    }

    stack<int> data;
    stack<int> aux; // 用于逆置
};
