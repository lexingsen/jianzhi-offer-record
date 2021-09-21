#include <iostream>
#include <vector>
using namespace std;


using pii = pair<int, int>; 
int UglyNumber(int n) {
    vector<int> arr(n + 1, 0);
    
    int p2 = 0;
    int p3 = 0;
    int p5 = 0;
    arr[0] = 1;
    int k = 1;
    for (int i = 1; i <= n; i++) {
        int a = arr[p2] * 2;
        int b = arr[p3] * 3;
        int c = arr[p5] * 5;
        int mi = min(a, min(b, c));
        if (mi == a) {
            p2++;
        }
        if (mi == b) {
            p3++;
        } 
        if (mi == c) {
            p5++;
        }
        arr[k++] = mi;
    }
    
    return arr[n-1];
}

