#include <bits/stdc++.h>
using namespace std;
 
void solve(long long a, long long b) {
    if (a == b) {
        cout << 0 << " " << 0 << endl;
        return;
    }
    if (b > a) swap(a, b);
    long long ans = a - b;
    long long moves = min(b % ans, ans - b % ans);
    cout << ans << " " << moves << endl;
    return;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        long long a, b;
        cin >> a >> b;
        solve(a, b);
    }
    return 0;
}