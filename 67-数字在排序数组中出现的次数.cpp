#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int getNumberOfK(vector<int>& nums , int k) {
        return upper_bound(nums.begin(), nums.end(), k) - lower_bound(nums.begin(), nums.end(), k);
    }
};