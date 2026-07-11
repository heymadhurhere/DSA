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
// const ll MOD = 1e9 + 7;
 
ll solve(vi& a, ll k, ll x) {
    ll n = sz(a);
    ll cnt = 0;
    if (n == 1) return 1;
 
    sort(all(a));
    vi tmp;
 
    for (ll i = 1; i < n; i++) {
        ll diff = a[i] - a[i - 1];
        if (diff > x) {
            if (diff % x == 0) {
                tmp.pb(diff / x - 1);
            } else {
                tmp.pb(diff / x);
            }
        }
    }
    sort(all(tmp));
    ll sum = 0;
    ll groups = sz(tmp) + 1;
    for (ll i = 0; i < sz(tmp); i++) {
        if (sum + tmp[i] <= k) {
            sum += tmp[i];
            groups--;
        } else {
            break;
        }
    }
    return groups;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n, k, x;
    cin >> n >> k >> x;
    vi a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll ans = solve(a, k, x);
    cout << ans << "
";
 
    return 0;
}