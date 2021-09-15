

// 要求不能使用乘除法、for、while、if、else、switch、case 等关键字及条件判断语句 (A?B:C)。
/*
短路规则 变相的表达的是一种判断
    a&&b a==false
    a||b a==true
*/
class Solution {
public:
    int getSum(int n) {
        int res = n;
        n > 0 && (res += getSum(n-1));
        return res;
    }
};