
class Solution {
public:
    int maxProductAfterCutting(int length) {
        if (length < 3) {
            return 1 * (length - 1);
        }
        int cnt = length % 3;
        int res = 1;
        if (cnt == 0) {
            for (int i = 1; i <= length / 3; i++) {
                res *= 3;
            }
        } else if (cnt == 1) {
            length = length - 4;
            for (int i = 1; i <= length / 3; i++) {
                res *= 3;
            }
            res *= 4;
        } else if (cnt == 2) {
            length = length - 2;
            for (int i = 1; i <= length / 3; i++) {
                res *= 3;
            }
            res *= 2;
        }
        return res;
    }
};