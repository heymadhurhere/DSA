class Solution {
public:
    void solve(vector<int>& candidates, int target, vector<int>& tmp,
               vector<vector<int>>& ans, int idx) {
        if (idx >= candidates.size()) {
            if (target == 0) {
                ans.push_back(tmp);
            }
            return;
        }
        if (target - candidates[idx] >= 0) {
            tmp.push_back(candidates[idx]);
            solve(candidates, target - candidates[idx], tmp, ans, idx);
            tmp.pop_back();
        }
        solve(candidates, target, tmp, ans, idx + 1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> tmp;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, tmp, ans, 0);
        return ans;
    }
};