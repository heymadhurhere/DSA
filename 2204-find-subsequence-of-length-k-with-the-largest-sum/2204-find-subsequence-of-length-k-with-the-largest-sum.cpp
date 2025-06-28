class Solution {
public:
    // void solve(vector<int>& nums, int k, int sum, int& maxi, int idx,
    //            vector<int>& temp, vector<int>& ans) {
    //     if (temp.size() == k) {
    //         if (sum > maxi) {
    //             maxi = sum;
    //             ans = temp;
    //         }
    //         return;
    //     }
    //     if (idx >= nums.size()) {
    //         return;
    //     }
    //     temp.push_back(nums[idx]);
    //     solve(nums, k, sum + nums[idx], maxi, idx + 1, temp, ans);
    //     temp.pop_back();
    //     solve(nums, k, sum, maxi, idx + 1, temp, ans);
    // }
    // vector<int> maxSubsequence(vector<int>& nums, int k) {
    //     int maxi = INT_MIN;
    //     vector<int> temp;
    //     vector<int> ans;
    //     solve(nums, k, 0, maxi, 0, temp, ans);
    //     return ans;
    // }

    static bool customSort(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    }

    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> temp;
        // pair => {val, idx};
        for (int i = 0; i < nums.size(); i++) {
            temp.push_back({nums[i], i});
        }
        sort(begin(temp), end(temp), greater<pair<int, int>>());
        vector<pair<int, int>> arr;
        arr.insert(arr.end(), temp.begin(), temp.begin() + k);
        sort(arr.begin(), arr.end(), customSort);
        vector<int> ans;
        for (auto& it : arr) {
            ans.push_back(it.first);
        }
        return ans;
    }
};