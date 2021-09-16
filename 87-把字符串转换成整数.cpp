
#include <string>
#include <iostream>
#include <climits>
using namespace std;


class Solution {
public:
    using ll = long long;
    int strToInt(string str) {
        int i = 0;
        while (i < str.size() && str[i] == ' ') {
            i++;
        }
        bool neg = false;
       
        if (str[i] == '-') {
            neg = true;
            i++;
        } else if (str[i]=='+') {
            i++;
        }
        
        ll num = 0;
        while (i < str.size() && isdigit(str[i])) {
            num = num * 10 + str[i] - '0';
            if (neg && (-1*num) <= INT_MIN) {
                return INT_MIN;
            } else if (num > INT_MAX) {
                return INT_MAX;
            }
            i++;
            
        }
        
        neg ? num = -num : num;
        if (num > INT_MAX) {
            return INT_MAX;
        } else if (num < INT_MIN) {
            return INT_MIN;
        } else {
            return num;
        }
    }
};


int main() {
    cout << INT_MIN << endl;
    return 0;
}