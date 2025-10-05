class Solution {
public:
    bool ship(vector<int>& weights, int days, int mid) {
        int cnt = 1;
        int sum = 0;
        for (int i = 0; i < weights.size(); i++) {
            if (sum + weights[i] <= mid) {
                sum += weights[i];
            } else {
                sum = weights[i];
                cnt++;
            }
        }
        return cnt <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int s = *max_element(weights.begin(), weights.end());
        int e = accumulate(weights.begin(), weights.end(), 0);
        int res = -1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (ship(weights, days, mid)) {
                res = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return res;
    }
};