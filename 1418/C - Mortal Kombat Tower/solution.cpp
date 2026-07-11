#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define all(x) x.begin(), x.end()
#define sz(x) (ll) x.size()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<ll, ll>
#define vpii vector<pii>
 
const int MOD = 1e9 + 7;
 
const ll INF = 1e18;
 
ll f(ll idx, ll chance, vi& a, vvi& dp) {
    if (idx >= sz(a)) return 0;
    if (dp[idx][chance] != -1) return dp[idx][chance];
    ll fn1 = INF, fn2 = INF, me1 = INF, me2 = INF;
    if (chance == 0) {
        fn1 = a[idx] + f(idx + 1, 1, a, dp);
        if (idx + 1 < sz(a)) {
            fn2 = a[idx] + a[idx + 1] + f(idx + 2, 1, a, dp);
        }
    } else if (chance == 1) {
        me1 = f(idx + 1, 0, a, dp);
        if (idx + 1 < sz(a)) {
            me2 = f(idx + 2, 0, a, dp);
        }
    }
    return dp[idx][chance] = min({fn1, fn2, me1, me2});
}
 
void solve(vi& a)
{
    ll n = sz(a);
    vvi dp(n + 1, vi(2, -1));
    cout << f(0, 0, a, dp) << "
";
    return;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vi a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        solve(a);
    }
 
    return 0;
}