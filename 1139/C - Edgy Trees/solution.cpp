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
 
ll power(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}
 
 
void solve(ll n, ll k) {
    vvi adj(n);
    for (ll i = 0; i < n - 1; i++) {
        ll u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        if (c == 0) {
            adj[u].pb(v);
            adj[v].pb(u);
        }
    }
 
    ll ans = 0;
    ans = power(n, k);
    //ans -= n;
    vector<bool> vis(n, false);
    for (ll i = 0; i < n; i++) {
        if (!vis[i]) {
            ll m = 0;
            vi tmp;
            tmp.pb(i);
            vis[i] = true;
            while (!tmp.empty()) {
                ll curr = tmp.back();
                tmp.pop_back();
                m++;
                for (auto it : adj[curr]) {
                    if (!vis[it]) {
                        vis[it] = true;
                        tmp.pb(it);
                    }
                }
            }
            ll mk = power(m, k);
            ans = (ans - mk % MOD + MOD) % MOD;
        }
    }
    cout << ans << endl;
    return;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll n, k;
    cin >> n >> k;
    solve(n, k);
 
    return 0;
}