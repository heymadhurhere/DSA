#include <bits/stdc++.h>
using namespace std;
 
 
 
void solve(int a, int b) {
    int ans = INT_MAX;
    for (int i = 0; i <= 31; i++) {
        int nb = b + i;
        int op = i;
        if (nb == 1) continue;
        int na = a;
        while (na > 0) {
            na /= nb;
            op++;
        }
        ans = min(ans , op);
    }
    cout << ans << endl;
    return;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    long long t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        solve(a, b);
    }
    return 0;
}