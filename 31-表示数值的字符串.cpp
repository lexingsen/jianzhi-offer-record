#include <iostream>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        int i = 0;
        int j = s.size() - 1;
        // 过滤前导空格
        while (i <= j && s[i] == ' ') {
            i++;
        }
        // 过滤后置空格
        while (j >= 0 && s[j] == ' ') {
            j --;
        }
        // 说明s只有空格字符
        if (i > j) {
            return false;
        }
        s = s.substr(i, j - i + 1);
        // 去掉前置+ -
        if (s[0] == '+' || s[0] == '-') {
            s = s.substr(1);
        }
        // 去掉+或-   字符串为空或者只有一个字符并且为. 说明该字符串合法
        if (s.empty() || (s[0] == '.' && s.size() == 1)) {
            return false;
        }


        int dot = 0;
        int e = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                continue;
            } else if (s[i] == '.') {
                dot++;
                if (e || dot > 1) {
                    return false;
                }
            } else if (s[i] == 'e' || s[i] == 'E') {
                e++;
                // 1.e前面没有数字 !i
                // 2.e后面没有数字 i + 1 == s.size()
                // 3.e出现的次数大于1
                // 4..e  e前面有字符并且为.
                if (i + 1 == s.size() || !i || e > 1 || i == 1 && s[0] == '.') {
                    return false;
                }
                // e后边有+或-时， 后边需要有数字，如果没有就不合法
                if (s[i + 1] == '+' || s[i + 1] == '-') {
                    if (i + 2 == s.size()) {
                        return false;
                    } else {
                        i ++;
                    }
                }
            } else {
                return false;
            }
        }
        return true;
    }
};


int main() {
    return 0;
}