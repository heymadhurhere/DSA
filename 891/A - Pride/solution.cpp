#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define all(x) x.begin(), x.end()
#define sz(x) (ll) x.size()
 
const int MOD = 1e9 + 7;
 
const ll INF = 1e18;
 
void solve(vi& a) {
    ll n = sz(a);
    ll cnt = 0, ans = a[0];
    for (ll i = 0; i < n; i++) {
        ans = __gcd(ans, a[i]);
        if (a[i] == 1) cnt++;
    }
    if (ans > 1) {
        cout << -1 << endl;
        return;
    }
    if (cnt > 0) {
        cout << n - cnt << endl;
        return;
    }
    ll res = 2 * n;
    for (ll i = 0; i < n; i++) {
        ll tmp = a[i];
        for (ll j = i + 1; j < n; j++) {
            tmp = __gcd(tmp, a[j]);
            if (tmp == 1) {
                res = min(res, (n - 1) + (j - i));
                break;
            }
        }
    }
    cout << res << endl;
    return;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll n;
    cin >> n;
    vi a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    solve(a);
 
    return 0;
}