class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            int tmp = nums[i];
            if (tmp == 2) {
                ans.push_back(-1);
                continue;
            }
            bool fnd = false;
            for (int j = 0; j < tmp; j++) {
                if ((j | (j + 1)) == tmp) {
                    ans.push_back(j);
                    fnd = true;
                    break;
                }
            }
            if (!fnd) {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};