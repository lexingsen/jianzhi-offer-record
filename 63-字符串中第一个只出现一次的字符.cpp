#include <string>
#include <unordered_map>
using namespace std;


class Solution {
public:
    char firstNotRepeatingChar(string s) {
        char res = '#';
        unordered_map<char, int> hash;
        for (auto c: s) {
            hash[c]++;
        }
        for (auto c:s) {
            if (hash[c] == 1) {
                return c;
            }
        }
        return res;
    }
};