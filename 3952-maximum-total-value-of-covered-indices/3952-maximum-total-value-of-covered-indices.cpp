class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        int n = nums.size();
        long long ans = 0;

        int i = 0;
        while (i < n) {
            if (s[i] == '1') {
                int l = i;

                while (i < n && s[i] == '1') {
                    i++;
                }
                int r = i - 1;

                if (l == 0) {
                    for (int j = 0; j <= r; j++) {
                        ans += nums[j];
                    }
                } else {
                    long long curr = 0;
                    int mini = nums[l - 1];

                    for (int j = l - 1; j <= r; j++) {
                        curr += nums[j];
                        mini = min(mini, nums[j]);
                    }
                    ans += (curr - mini);
                }
            } else {
                i++;
            }
        }
        cout << ans;
        return ans;
    }
};