class Solution {
public:
    int countElements(vector<int>& nums) {
        map<int, int> mpp;
        for (auto it : nums) {
            mpp[it]++;
        }
        if (mpp.size() < 3) {
            return 0;
        }
        int ans = 0;
        for (auto it : mpp) {
            ans += it.second;
        }
        ans -= mpp.begin()->second;
        ans -= prev(mpp.end())->second;
        return ans;
    }
};