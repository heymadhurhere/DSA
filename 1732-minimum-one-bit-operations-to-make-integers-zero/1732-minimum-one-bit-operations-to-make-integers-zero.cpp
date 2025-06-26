class Solution {
public:
    int minimumOneBitOperations(int n) {
        if (n <= 1)
            return n;
        int cnt = 0;
        while ((1 << cnt) <= n)
            cnt++;
        return ((1 << cnt) - 1) - minimumOneBitOperations(n - (1 << (cnt - 1)));
    }
};