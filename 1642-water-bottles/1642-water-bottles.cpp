class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int rem = 0, ans = 0;
        while (numBottles > 0) {
            ans += numBottles;
            rem += numBottles;
            numBottles = rem / numExchange;
            rem %= numExchange;
        }
        return ans;
    }
};