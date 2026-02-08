class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> pref(n, 0);
        int m = bookings.size();
        for (int i = 0; i < m; i++) {
            int l = bookings[i][0];
            int r = bookings[i][1];
            int val = bookings[i][2];

            pref[l - 1] += val;
            if (r < n) {
                pref[r] -= val;
            }
        }
        for (int i = 1; i < n; i++) {
            pref[i] += pref[i - 1];
        }
        return pref;
    }
};