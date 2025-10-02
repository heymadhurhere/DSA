class Solution {
public:
    static bool custom(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mpp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++;
        }
        vector<int> ans;
        vector<pair<int, int>> vec(mpp.begin(), mpp.end());
        sort(vec.begin(), vec.end(), custom);
        for (auto& it : vec) {
            if (k > 0) {
                ans.push_back(it.first);
                k--;
            } else {
                break;
            }
        }
        return ans;
    }
};