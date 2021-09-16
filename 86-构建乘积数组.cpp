#include <vector>
using namespace std;


class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> res;
        for (int i = 0; i < A.size(); i++) {
            int ans = 1;
            for (int j = 0; j < i; j++) {
                ans *= A[j];
            }
            for (int j = i + 1; j < A.size(); ++j) {
                ans *= A[j];
            }
            res.emplace_back(ans);
        }
        return res;
    }
};