#include <string>
#include <iostream>
using namespace std;


class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) {
            return s.empty();
        }
        // s非空  s:axxx p:ayyy 或者  s:axxx p:.yyy 说明第一个字符匹配
        bool firstMatch = !s.empty() && (s[0] == p[0] || p[0] == '.');
        // p: x*    可以匹配x0次或者多次
        if (p.size() >= 2 && p[1] == '*') {
            // 1.匹配0次  2.匹配一次或者多次  s:aabb p:a*bb
            return isMatch(s, p.substr(2)) || (firstMatch && isMatch(s.substr(1), p));
        } else {
            return firstMatch && isMatch(s.substr(1), p.substr(1));
        }
    }
};