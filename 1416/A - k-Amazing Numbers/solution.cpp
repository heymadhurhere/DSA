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
 
void solve(vi& a)
{
    ll n = sz(a);
    vi last(n + 1, 0);
    vi maxGp(n + 1, 0);
 
    for (ll i = 0; i < n; i++) {
        ll cur = i + 1;
        ll gp = cur - last[a[i]];
        maxGp[a[i]] = max(maxGp[a[i]], gp);
        last[a[i]] = cur;
    }
 
    for (ll x = 1; x <= n; x++) {
        if (last[x] != 0) {
            ll gp = n + 1 - last[x];
            maxGp[x] = max(maxGp[x], gp);
        }
    }
 
    vi ans(n + 1, INF);
 
    for (ll x = 1; x <= n; x++) {
        if (maxGp[x] != 0) {
            ans[maxGp[x]] = min(ans[maxGp[x]], x);
        }
    }
 
    for (ll i = 1; i <= n; i++) {
        ans[i] = min(ans[i], ans[i - 1]);
    }
 
    for (ll i = 1; i <= n; i++) {
        if (ans[i] == INF) {
            cout << -1 << " ";
        } else {
            cout << ans[i] << " ";
        }
    }
    cout << endl;
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