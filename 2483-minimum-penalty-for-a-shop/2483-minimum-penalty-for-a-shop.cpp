class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        vector<int> open(n + 1), close(n + 1);
        int penalty = 0;

        for (int i = 0; i < n; i++) {
            if (customers[i] == 'N') {
                penalty++;
            }
            open[i + 1] = penalty;
        }

        penalty = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (customers[i] == 'Y') {
                penalty++;
            }
            close[i] = penalty;
        }

        penalty = INT_MAX;
        int ans = 0;

        for (int i = 0; i < n + 1; i++) {
            if (open[i] + close[i] < penalty) {
                penalty = open[i] + close[i];
                ans = i;
            }
        }
        return ans;
    }
};