class Solution {
public:
    int numberOf1Between1AndN_Solution(int n) {
        int base = 1;
        int res = 0;
        while (base <= n) {
            int a = n / base;
            int b = n % base;
            int cur = a % 10;
            a /= 10;

            if (cur > 1) {
                res += (a + 1) * base;
            } else if (cur == 1) {
                res += (a * base + b + 1);
            } else {
                res += (a * base);
            }
            base *= 10;
        }
        return res;
    }
};