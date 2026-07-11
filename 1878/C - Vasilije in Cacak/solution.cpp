#include <bits/stdc++.h>
using namespace std;
 
string solve(long long n, long long k, long long x) {
    long long minSum = k * (k + 1) / 2;
 
    long long total = n * (n + 1) / 2;
    long long exclude = (n - k) * (n - k + 1) / 2;
    long long maxSum = total - exclude;
 
    return (x < minSum || x > maxSum) ? "NO" : "YES";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while (t--) {
        long long n, k, x;
        cin >> n >> k >> x;
        cout << solve(n, k, x) << '
';
    }
    return 0;
}