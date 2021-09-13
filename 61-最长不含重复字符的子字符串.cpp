#include <unordered_map>
#include <string>
using namespace std;


class Solution {
public:
    int longestSubstringWithoutDuplication(string s) {
        int l = 0;
        int r = 0;
        int res = 0;
        unordered_map<char, int> hash;
        while (r < s.size()) {
            char a = s[r];
            r++;
            hash[a]++;

            
            while (hash[a] > 1) {
                char d = s[l++];
                hash[d]--;
            }
            res = max(res, r - l);
        }
        return res;
    }
};