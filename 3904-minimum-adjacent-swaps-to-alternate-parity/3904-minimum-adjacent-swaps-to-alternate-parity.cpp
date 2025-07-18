class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<int> e, o;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0)
                e.push_back(i);
            else
                o.push_back(i);
        }

        int n = nums.size();
        int even = e.size();
        int odd = o.size();

        if (abs(even - odd) > 1)
            return -1;

        int ans = INT_MAX;

        if (even >= odd)
            ans = min(ans, solve(e));
        if (odd >= even)
            ans = min(ans, solve(o));

        return ans;
    }
    int solve(vector<int> nums) {
        int c = 0;
        for (int i = 0; i < nums.size(); i++) {
            c += abs(nums[i] - 2 * i);
        }

        return c;
    }
};