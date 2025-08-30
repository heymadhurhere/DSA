class Solution {
public:
    long long flowerGame(int n, int m) {
        // n = x, m = y;
        long long xOdd = 0, xEven = 0;
        if (n % 2 == 0) {
            xOdd = n / 2;
        } else {
            xOdd = n / 2 + 1;
        }
        xEven = n - xOdd;
        long long yOdd = 0, yEven = 0;
        if (m % 2 == 0) {
            yOdd = m / 2;
        } else {
            yOdd = m / 2 + 1;
        }
        yEven = m - yOdd;
        return (xOdd * yEven) + (yOdd * xEven);
    }
};