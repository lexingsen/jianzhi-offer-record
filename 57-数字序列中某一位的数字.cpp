#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int digitAtIndex(int n) {
        int start = 1;
        long  digits = 1;
        long  count = 9 * start * digits;
        while (n > count) {
            n -= count;
            start *= 10;
            digits += 1;
            count = 9 * start * digits;
        }
        long  num = start + (n - 1) / digits;
        int index = (n - 1) % digits;
        string res = to_string(num);
        return res[index] - '0';
    }
};

#if 0
class Solution {
public:
    int findNthDigit(int n) {
        int digit = 1; // 记录位数，初始为一位数
        long start = 1; // 记录某一位数起始的第一个数，初始为一位数起点1
        long count = digit * start * 9; // 记录某一位数所有包含的数字个数，初始为一位数个数9
        /*
        *  1、判断第n位数字所属的数是几位数
        *  当n > count表明第n为数字所属的数比当前位数更高
        */
        while (n > count) {
            n -= count;
            digit += 1;
            start *= 10;
            count = digit * start * 9;
        }
        /*
        *  2、判断第n位数字属于哪一个数
        *  注意：第一步结束之后n已经改变了，是减去前几个不属于的位数的count之后的值
        *  (n - 1) / digit计算的是第n位数字属于当前位数里面的第几个数
        *  start是当前位数的第0个数，所以要n-1
        *  算出来之后再加上start就是第n位数字所属的数
        *  比如：
        *  n=5，start=1，digit=1
        *  number = 1 + (5-1)/1 = 5
        */
        long number = start + (n - 1) / digit;
        /*
        *  3、判断第n位数字在第二步找出的数中是第几位
        *  (n - 1) % digit计算的就是第几位（除去几个digit，余数就是所在的位数）
        *  比如：
        *  n=20，
        *  第一步后：n=11, satrt=10, digit=2
        *  第二步后：number= 15
        *  第三步：(n-1)%digit = 0说明是15这个数的第一位
        *  与字符串‘0’相减返回成数字即可
        */
        string s_number = to_string(number);
        return s_number[(n - 1) % digit] - '0';
    }
};
#endif