class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> tmp(n);

        for (int i = 0; i < n; i++) {
            int num = nums[i];
            vector<int> fac;
            for (int p = 2; p * p <= num; p++) {
                if (num % p == 0) {
                    fac.push_back(p);
                    while (num % p == 0) {
                        num /= p;
                    }
                }
            }
            if (num > 1) {
                fac.push_back(num);
            }
            tmp[i] = fac;
        }
        unordered_map<int, int> freq;

        int l = 0, r = 0, ans = 0;

        while (r < n) {
            for (int p : tmp[r])
                freq[p]++;

            while (freq.size() > k) {
                for (int p : tmp[l]) {
                    freq[p]--;
                    if (freq[p] == 0) {
                        freq.erase(p);
                    }
                }
                l++;
            }
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};