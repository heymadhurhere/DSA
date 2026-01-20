class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int l = 0;
        int r = arr.back();
        int ans = r;

        int n = arr.size();
        vector<int> prefSum(n);
        prefSum[0] = arr[0];
        for (int i = 1; i < n; i++) {
            prefSum[i] = prefSum[i - 1] + arr[i];
        }

        int diff = abs(target - prefSum[n - 1]);

        while (l <= r) {
            int mid = l + (r - l) / 2;

            int idx = upper_bound(arr.begin(), arr.end(), mid) - arr.begin();

            int sum = (idx == 0 ? 0 : prefSum[idx - 1]) + (n - idx) * mid;

            int newDiff = abs(sum - target);

            if (newDiff < diff || (newDiff == diff && mid < ans)) {
                diff = newDiff;
                ans = mid;
            }

            if (sum < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return ans;
    }
};