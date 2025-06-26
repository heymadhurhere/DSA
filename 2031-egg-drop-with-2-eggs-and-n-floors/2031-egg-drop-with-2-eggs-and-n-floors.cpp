class Solution {
public:
    int twoEggDrop(int n) {
        int low = 1, high = 1000, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long sum = 1ll * mid * (mid + 1) / 2;
            if (sum >= n) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};