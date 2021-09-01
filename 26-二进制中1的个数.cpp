
/*
强制转化为为无符号数，防止死循环
算术移位  逻辑移位
*/
class Solution {
public:
    int NumberOf1(int n) {
        int cnt = 0;
        unsigned int m = (unsigned int)n;
        while (m) {
            cnt += (m) & 1;
            m >>= 1;
        }
        return cnt;
    }
};