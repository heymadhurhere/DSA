#include <bits/stdc++.h>
using namespace std;
 
long long solve(long long a, long long b, vector<long long>& arr) {
    long long n = arr.size();
    long long cnt = b;
    for (int i = 0; i < n; i++) {
        cnt += min(arr[i], a - 1);
   }
   return cnt;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while (t--) {
        long long a, b, n;
        cin >> a >> b >> n;
        vector<long long> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << solve(a, b, arr) << '
';
    }
    return 0;
}