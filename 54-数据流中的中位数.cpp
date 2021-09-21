#include <queue>
#include <vector>
using namespace std;




/*
动态获取中位数

输入 1, 2, 3, 4
输出 1, 1.5, 2, 2.5

思路
1.维护两个堆  大根堆和小根堆
大根堆存放较小的那部分数字
小根堆存放较大的那部分数字

当前中位数 = (大根堆堆顶元素+小根堆堆顶元素)/2

1.逆序交换
2.下边元素太多，转移上去一个
*/


class Solution {
public:
    void insert(int num){
        max_heap.push(num);
        if (min_heap.size() && max_heap.top() > min_heap.top()) {
            int a = max_heap.top();
            max_heap.pop();
            max_heap.push(min_heap.top());
            min_heap.pop();
            min_heap.push(a);
        }

        if (max_heap.size() > min_heap.size() + 1) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
    }

    double getMedian(){
        if (max_heap.size() + min_heap.size() & 1) {
            return max_heap.top();
        } else {
            return (max_heap.top() + min_heap.top()) / 2.0;
        }
    }
private:
    priority_queue<int, vector<int>, greater<int>> min_heap;
    priority_queue<int, vector<int>, less<int>> max_heap;
};