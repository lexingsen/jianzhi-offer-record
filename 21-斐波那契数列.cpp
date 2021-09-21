class Solution {
public:
    using ll = long long;
    #define N 41
    ll f[N];
    int Fibonacci(int n) {
        f[0] = 0;
        f[1] = 1;
        for (int i = 2; i <= n; i++) {
            f[i] = f[i - 1] + f[i - 2];
        }
        return f[n];
    }
};