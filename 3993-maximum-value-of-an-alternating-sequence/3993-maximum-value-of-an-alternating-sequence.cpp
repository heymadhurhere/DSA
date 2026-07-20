using ll = long long;
class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if (n == 1)
            return s;
        ll inc = n / 2;
        ll dec = inc - 1;
        return s + inc * m - dec;
    }
};