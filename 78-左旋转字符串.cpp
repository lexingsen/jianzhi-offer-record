class Solution {
public:
    void move(string& s, int x, int y) {
        while (x < y) {
            swap(s[x], s[y]);
            x++;
            y--;
        }
    }
    
    string leftRotateString(string str, int n) {
        string t = str;
        move(t, 0, n - 1);
        move(t, n, t.size() - 1);
        move(t, 0, t.size() - 1);
        return t;
    }
};