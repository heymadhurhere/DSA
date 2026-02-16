class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        vector<int> zero(n + 1);
        zero[0] = 0;
        if (nums[0] == 0)
            cnt++;
        for (int i = 1; i < n; i++) {
            zero[i] = cnt;
            if (nums[i] == 0)
                cnt++;
        }
        zero[n] = cnt;
        cnt = 0;
        vector<int> one(n + 1);
        one[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] == 1)
                cnt++;
            one[i] = cnt;
        }
        int high = INT_MIN;
        for (int i = 0; i <= n; i++) {
            high = max(high, zero[i] + one[i]);
        }
        vector<int> ans;
        for (int i = 0; i < n + 1; i++) {
            if (zero[i] + one[i] == high) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};