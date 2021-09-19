#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;


class Solution {
public:
    string printMinNumber(vector<int>& nums) {
        vector<string> t;
        for (int i = 0; i < nums.size(); i++) {
            t.emplace_back(to_string(nums[i]));
        }
        sort(t.begin(), t.end(), [] (const string &a, const string &b) {return a+b < b+a;});
        string res = "";
        for (auto x: t) {
            res += x;
        }
        return res;
    }
};

int main() {
    vector<int> nums = {3, 32, 321};
    Solution sol;
    cout << sol.printMinNumber(nums);
    return 0;
}