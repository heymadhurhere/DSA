class Solution {
public:
    int maxProfit(vector<int>& arr) {
         int n = arr.size();
        int i = 0, j = 1;
        int ans = 0;
        while (j < n) {
            if (arr[j] > arr[j - 1]) {
                j++;
            } else {
                ans += arr[j - 1] - arr[i];
                i = j;
                j++;
            }
        }
        ans += arr[n - 1] - arr[i];
        return ans;
    }
};