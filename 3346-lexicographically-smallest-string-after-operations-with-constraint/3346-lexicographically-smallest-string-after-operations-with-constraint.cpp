class Solution {
public:
    string getSmallestString(string s, int k) {
        for (auto& it : s) {
            int dis = min(it - 'a', 'z' - it + 1);
            if (k >= dis) {
                k -= dis;
                it = 'a';
            } else {
                it -= k;
                break;
            }
        }
        return s;
    }
};