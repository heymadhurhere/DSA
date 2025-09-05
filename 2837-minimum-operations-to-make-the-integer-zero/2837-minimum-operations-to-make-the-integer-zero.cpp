class Solution {
public:
    int countSetBits(long long n) {
    int count = 0;
    while (n > 0) {
        if (n & 1) {
            count++;
        }
        n >>= 1;
    }
    return count;
}
bool canBeSumOfPowersOf2(long long N, int n) {
    if (n > N) {
        return false;
    }
    int min_terms = countSetBits(N);
    if (n < min_terms) {
        return false;
    }
    return true;
}
    int makeTheIntegerZero(int num1, int num2) {
        if (num1 <= num2) return -1;
        // int n = abs(num1 / num2);
        for (int i = 1; i <= 60; i++) {
            long long rem = (long long)num1 - 1LL * i * num2;
            if (rem < 0) break;
            if (canBeSumOfPowersOf2(rem, i)) {
                return i;
            }
        }
        return -1;
    }
};