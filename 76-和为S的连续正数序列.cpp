#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > findContinuousSequence(int sum) {
        vector<vector<int>> ans;

        for (int i = 1, j = 1, s = 1; i <= sum; i++) {
            while (s < sum) {
                // j++;
                // s += j;
                
                s += ++j;
            }
            if (s == sum && j - i + 1 > 1) {
                vector<int> line;
                for (int k = i; k <= j; ++k) {
                    line.push_back(k);
                }
                ans.push_back(line);
            }
            // sum > s
            s -= i;
        }
        return ans;
    }
};