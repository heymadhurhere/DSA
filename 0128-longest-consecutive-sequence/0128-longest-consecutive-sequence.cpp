class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]]++;
        }
        int ans = 0;
        auto it = mpp.begin();
        while (it != mpp.end()) {
            int cnt = 1;
            auto curr = it;
            auto aft = next(it);
            while (aft != mpp.end() && aft->first == curr->first + 1) {
                cnt++;
                curr = aft;
                aft = next(curr);
            }
            ans = max(ans, cnt);
            it = next(curr);
        }
        return ans;
    }
};