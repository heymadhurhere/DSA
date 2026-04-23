class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int, vector<int>> mpp;
        unordered_map<int, vector<long long>> pre;

        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int v = nums[i];
            mpp[nums[i]].push_back(i);

            long long last = pre[v].empty() ? 0LL : pre[v].back();
            pre[v].push_back(last + i);
        }

        vector<long long> ans;
        for (int i = 0; i < n; i++) {
            int v = nums[i];
            auto& arr = mpp[v];
            auto& p = pre[v];

            long long tot = arr.size();

            long long idx =
                lower_bound(arr.begin(), arr.end(), i) - arr.begin();

            long long l_sum = (idx > 0) ? p[idx - 1] : 0LL;
            long long l_dist = (idx * i) - l_sum;

            long long r_sum = p.back() - p[idx];
            long long r_cnt = tot - idx - 1;
            long long r_dist = r_sum - (r_cnt * i);

            ans.push_back(l_dist + r_dist);
        }
        return ans;
    }
};