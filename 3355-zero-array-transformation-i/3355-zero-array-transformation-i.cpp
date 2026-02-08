class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> pref(n, 0);
        for (int i = 0; i < queries.size(); i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            pref[l] += 1;
            if (r + 1 < n) {
                pref[r + 1] -= 1;
            }
        }

        for (int i = 1; i < n; i++) {
            pref[i] += pref[i - 1];
        }

        for (int i = 0; i < n; i++) {
            if (pref[i] < nums[i])
                return false;
        }
        return true;
    }
};