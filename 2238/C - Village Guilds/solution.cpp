#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<ll, ll>
#define vi vector<ll>
#define vpii vector<pii>
#define all(x) x.begin(), x.end()
#define sz(x) (ll)(x).size()
#define F first
#define S second
 
void solve(vi &a) {
    ll n = sz(a) + 1;
 
    vi par(n), dep(n), mx1(n), mx2(n, -1);
 
    mx1[0] = 0;
 
    for (ll i = 1; i < n; i++) {
        par[i] = a[i - 1] - 1;
        dep[i] = dep[par[i]] + 1;
        mx1[i] = dep[i];
    }
 
    ll ans = n;
 
    for (ll i = n - 1; i >= 1; i--) {
        ll p = par[i];
 
        if (mx1[i] > mx1[p]) {
            mx2[p] = mx1[p];
            mx1[p] = mx1[i];
        } else if (mx1[i] > mx2[p]) {
            mx2[p] = mx1[i];
        }
    }
 
    for (ll i = 0; i < n; i++) {
        if (mx2[i] > dep[i])
            ans += (mx2[i] - dep[i]);
    }
 
    cout << ans << '
';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
 
    while (t--) {
        ll n;
        cin >> n;
 
        vi a(n - 1);
        for (ll i = 0; i < n - 1; i++)
            cin >> a[i];
 
        solve(a);
    }
 
    return 0;
}