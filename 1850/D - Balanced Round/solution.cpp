#include <bits/stdc++.h>
using namespace std;
 
void solve(vector<long long>& arr, long long k) {
    long long n = arr.size();
    long long maxLen = 1;
    if (n == 1) {
        cout << 0 << endl;
        return;
    }
    sort(arr.begin(), arr.end());
    long long i = 0, j = 1;
    while (j < n) {
        if (arr[j] - arr[j - 1] <= k) {
            maxLen = max(maxLen, j - i + 1);
        }
        else {
            i = j;
        }
        j++;
    }
    cout << n - maxLen << endl;
}
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        vector<long long> arr(n);
        for (long long i = 0; i < n; i++) {
            cin >> arr[i];
        }
        solve(arr, k);
    }
    return 0;
}