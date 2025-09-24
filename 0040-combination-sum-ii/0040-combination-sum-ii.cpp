class Solution {
public:
    void solve(int idx, vector<int>& candidates, int target,
               vector<vector<int>>& ans, vector<int>& tmp) {
        if (target == 0) {
            ans.push_back(tmp);
        }
        for (int i = idx; i < candidates.size(); i++) {
            if (i > idx && candidates[i] == candidates[i - 1])
                continue;
            if (target < candidates[i])
                break;
            if (target >= candidates[i]) {
                tmp.push_back(candidates[i]);
                solve(i + 1, candidates, target - candidates[i], ans, tmp);
                tmp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> tmp;
        solve(0, candidates, target, ans, tmp);
        return ans;
    }
};