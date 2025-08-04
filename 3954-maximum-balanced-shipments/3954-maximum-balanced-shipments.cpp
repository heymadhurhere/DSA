class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int j = 0, n = weight.size();
        bool fnd = false;
        int maxi = INT_MIN, cnt = 0;
        while (j < n) {
            maxi = max(maxi, weight[j]);
            if (weight[j] < maxi) {
                cnt++;
                fnd = true;
            }
            j++;
            if (fnd && j < n) {
                maxi = weight[j];
                fnd = false;
            }
        }
        return cnt;
    }
};