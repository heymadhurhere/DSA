class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        vector<bool> bits(32, false);
        bits[2] = true, bits[3] = true, bits[5] = true, bits[7] = true,
        bits[11] = true, bits[13] = true, bits[17] = true, bits[19] = true,
        bits[23] = true, bits[29] = true, bits[31] = true;
        int cnt = 0;
        for (int i = left; i <= right; i++) {
            int tmp = __builtin_popcount(i);
            if (bits[tmp])
                cnt++;
        }
        return cnt;
    }
};