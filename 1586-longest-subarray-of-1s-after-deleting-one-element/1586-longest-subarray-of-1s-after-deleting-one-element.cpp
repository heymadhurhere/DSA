class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return 0;
        }
        int i = 0, j = 0;
        vector<int> tmp;
        while (j < n) {
            if (nums[j] == 1) {
                j++;
            } else {
                tmp.push_back(j - i);
                j++;
                i = j;
            }
        }
        tmp.push_back(j - i);
        if (tmp.size() == 1)
            return tmp[0] - 1;
        int ans = 0;
        for (int i = 1; i < tmp.size(); i++) {
            ans = max(ans, tmp[i - 1] + tmp[i]);
        }
        return ans;
    }
};