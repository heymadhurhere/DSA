class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int ans = INT_MAX;
        int n = arr.size();
        int l = 0, r = n - 1;

        while (l < n - 1 && arr[l] <= arr[l + 1])
            l++;
        if (l == n - 1)
            return 0;

        while (r > 0 && arr[r - 1] <= arr[r])
            r--;

        ans = min(n - l - 1, r);

        for (int i = 0; i <= l; i++) {
            int j =
                lower_bound(arr.begin() + r, arr.end(), arr[i]) - arr.begin();
            ans = min(ans, j - i - 1);
        }
        return ans;
    }
};