#include <queue>
#include <unordered_map>
using namespace std;


class Solution{
public:
    //Insert one char from stringstream
    queue<char> q;  // 维护只出现一次的字符的队列 fifo 保证了顺序
    unordered_map<char, int> hash; // 统计字符出现次数的哈希表
    void insert(char ch){
        hash[ch]++;
        if (hash[ch] > 1) {
            while (q.size() && hash[q.front()] > 1) {
                q.pop();
            }
        } else {
            // hash[ch] == 1   字符ch第一次出现, 插入队列
            q.push(ch);
        }
    }
    //return the first appearence once char in current stringstream
    char firstAppearingOnce(){
        return q.size() ? q.front() : '#';
    }
};