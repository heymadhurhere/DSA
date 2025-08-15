class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        int bits = floor(log2(n)) + 1;
        int setBits = __builtin_popcount(n);
        if ((n & (n - 1)) == 0 && (bits - setBits) % 2 == 0) return true;
        return false;
    }
};