class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            int del = nums[i];
            if (del == 0) {
                res[i] = nums[i];
                continue;
            }
            del = ((del % n) + n) % n;
            int idx = (i + del) % n;
            res[i] = nums[idx];
        }
        return res;
    }
};