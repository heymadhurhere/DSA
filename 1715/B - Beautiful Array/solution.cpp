#include <bits/stdc++.h>
using namespace std;
 
void solve(long long n, long long k, long long b, long long s)
{
    if (k * b > s || k * b + n * (k - 1) < s) {
        cout << -1 << endl;
        return;
    }
    vector<long long> arr(n, 0);
    arr[0] = k * b;
    s -= k * b;
    for (long long i = 0; i < n; i++) {
        arr[i] += min(k - 1, s);
        s -= min(k - 1, s);
    }
    for (long long i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long t;
    cin >> t;
    while (t--) {
        long long n, k, b, s;
        cin >> n >> k >> s >> b;
        solve(n, k, s, b);
    }
    return 0;
}