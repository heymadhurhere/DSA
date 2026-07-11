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
 
 
void solve(vi& u, vi& cost) {
    ll n = sz(u);
 
    map<ll, vi> mpp;
 
    for (ll i = 0; i < n; i++) {
        mpp[u[i]].pb(cost[i]);
    }
 
    for (auto &it : mpp) {
        sort(it.S.rbegin(), it.S.rend());
    }
 
    for (auto &it : mpp) {
        for (ll i = sz(it.S) - 2; i >= 0; i--) {
            it.S[i] += it.S[i + 1];
        }
    }
 
    vi ans(n, 0);
 
    for (auto &it : mpp) {
        ll m = sz(it.S);
        for (ll i = 1; i <= m; i++) {
            ll rem = m % i;
 
            ll contr = it.S[0];
            if (rem > 0) {
                contr -= it.S[m - rem];
            }
            ans[i - 1] += contr;
        }
    }
 
    for (ll i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}
 
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
 
    while (t--) {
        ll n;
        cin >> n;
        vi u(n);
        vi cost(n);
        for (ll i = 0; i < n; i++) {
            cin >> u[i];
        }
        for (ll i = 0; i < n; i++) {
            cin >> cost[i];
        }
        solve(u, cost);
    }
    return 0;
}