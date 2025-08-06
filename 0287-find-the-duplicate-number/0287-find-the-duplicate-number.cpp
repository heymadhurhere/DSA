class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int s = nums[0], f = nums[0];
        while (true) {
            s = nums[s];
            f = nums[nums[f]];
            if (s == f) break;
        }
        int ans = nums[0];
        while (ans != s) {
            s = nums[s];
            ans = nums[ans];
        }
        return s;
    }
};