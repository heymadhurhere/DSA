class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int sum = 0;
        int n = grumpy.size();
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0) {
                sum += customers[i];
            }
        }
        int ans = 0;
        int res = INT_MIN;
        for (int i = 0; i < minutes; i++) {
            if (grumpy[i] == 1) {
                ans += customers[i];
            }
        }
        res = max(res, sum + ans);
        int j = minutes, i = 1;
        while (j < n) {
            if (grumpy[i - 1] == 1) {
                ans -= customers[i - 1];
            }
            if (grumpy[j] == 1) {
                ans += customers[j];
            }
            res = max(res, sum + ans);
            i++;
            j++;
        }
        return res;
    }
};