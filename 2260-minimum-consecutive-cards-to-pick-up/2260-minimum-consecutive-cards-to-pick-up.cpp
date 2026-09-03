class Solution {
public:
    int minimumCardPickup(vector<int>& c) {
        int n = c.size();
        unordered_map<int, int> mpp;
        int ans = INT_MAX;
        int i = 0, j = 0;

        while (i <= j && j < n) {
            int num = c[j];
            mpp[num]++;
            while (mpp[num] == 2) {
                ans = min(ans, j - i + 1);
                mpp[c[i]]--;
                i++;
            }
            j++;
        }
        if (ans == INT_MAX)
            return -1;
        return ans;
    }
};