class Solution {
public:
    const int MOD = 1e9 + 7;
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto& it : nums) {
            pq.push(it);
        }
        while (k--) {
            int top = pq.top();
            pq.pop();
            top++;
            pq.push(top);
        }
        int ans = 1;
        while (!pq.empty()) {
            int top = pq.top();
            pq.pop();
            ans = (1LL * ans * top) % MOD;
        }
        return ans % MOD;
    }
};