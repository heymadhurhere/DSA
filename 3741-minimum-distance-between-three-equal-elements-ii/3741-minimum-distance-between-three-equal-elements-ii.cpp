class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mpp;

        for (int i = 0; i < n; i++) {
            mpp[nums[i]].push_back(i);
        }

        int ans = INT_MAX;

        for (auto& it : mpp) {
            if (it.second.size() > 2) {
                for (int i = 0; i < it.second.size() - 2; i++) {
                    int diff = abs(it.second[i] - it.second[i + 1]) +
                               abs(it.second[i + 1] - it.second[i + 2]) +
                               abs(it.second[i + 2] - it.second[i]);
                    ans = min(ans, diff);
                }
            }
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};