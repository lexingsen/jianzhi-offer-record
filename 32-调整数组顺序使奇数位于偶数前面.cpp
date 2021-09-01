#include <iostream>
#include <vector>
using namespace std;


/*
双指针算法
*/

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int l = 0;
        int r = array.size() - 1;
        while (l < r) {
            if (array[l] % 2 == 1) {
                l++;
            } else if (array[r] % 2 == 0) {
                r--;
            } else {
                std::swap(array[l], array[r]);
                l++, r--;  
            }
        }
    }
};

