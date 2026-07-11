#include <bits/stdc++.h>
using namespace std;
 
long long solve(vector<long long>& arr) {
    long long n = arr.size();
    long long cnt = 0;
    for (int i = 2; i < n; i++) {
        long long maxi = max(2*arr[i], arr[n - 1]) - arr[i];
        for (int j = 1; j < i; j++) {
            long long rqd = maxi - arr[j] + 1;
            long long idx = lower_bound(arr.begin(), arr.begin() + j, rqd) - arr.begin();
            cnt += (j - idx);
        }
    }
    return cnt;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << solve(arr) << endl;
    }
    return 0;
}