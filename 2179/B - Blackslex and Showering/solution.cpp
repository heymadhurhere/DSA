#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<long long, long long>
#define vi vector<long long>
#define vpii vector<pii>
#define all(s) s.begin(), s.end()
#define sz(s) (ll)(s).size()
#define F first
#define S second
const ll MOD = 1e9 + 7;
 
ll solve(vi& a) {
    ll n = sz(a);
    ll ans = 0;
 
    for (ll i = 1; i < n; i++) {
        ans += abs(a[i] - a[i - 1]);
    }
 
    ll res = ans;
 
    res = min(res, ans - abs(a[1] - a[0]));
    res = min(res, ans - abs(a[n - 1] - a[n - 2]));
 
    for (ll i = 1; i < n - 1; i++) {
        ll curr = ans;
        curr -= abs(a[i] - a[i - 1]);
        curr -= abs(a[i + 1] - a[i]);
        curr += abs(a[i + 1] - a[i - 1]);
        res = min(res, curr);
    }
 
    return res;
}
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    if (cin >> t) {
        while (t--)
        {
            ll n;
            cin >> n;
            vi a(n);
            for (ll i = 0; i < n; i++) {
                cin >> a[i];
            }
 
            if (n <= 2) {
                cout << 0 << "
";
                continue;
            }
 
            ll ans = solve(a);
            cout << ans << "
";
        }
    }
 
    return 0;
}