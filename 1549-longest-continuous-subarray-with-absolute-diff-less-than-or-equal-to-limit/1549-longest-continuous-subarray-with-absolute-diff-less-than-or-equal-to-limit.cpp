class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        int i = 0;
        int ans = 0;
        deque<int> incr, decr;
        for (int j = 0; j < n; j++) {
            int el = nums[j];
            while (!decr.empty() && el > decr.back()) {
                decr.pop_back();
            }
            decr.push_back(el);
            while (!incr.empty() && el < incr.back()) {
                incr.pop_back();
            }
            incr.push_back(el);
            while (decr.front() - incr.front() > limit) {
                if (decr.front() == nums[i]) {
                    decr.pop_front();
                }
                if (incr.front() == nums[i]) {
                    incr.pop_front();
                }
                i++;
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};