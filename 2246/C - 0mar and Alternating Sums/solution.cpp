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
 
ll power(ll b, ll e) {
    ll ans = 1;
    b %= MOD;
    while (e > 0) {
        if (e % 2 == 1) {
            ans = (ans * b) % MOD;
        }
        b = (b * b) % MOD;
        e /= 2;
    }
    return ans;
}
 
void solve(vi& a) {
    ll n = sz(a);
    ll c = 0;
 
    for (ll i = 0; i < n; i++) {
        if (a[i] == -1) c++;
    }
 
    if (c == n) {
        ll ans = (c > 0 ? power(2, c - 1) : 1);
        cout << ans << "
";
        return;
    }
 
    ll w0 = 1;
    ll k = 0;
    ll i = c; 
 
    while (i < n) {
        ll j = i;
        
        while (j < n && a[j] == a[i]) {
            j++;
        }
 
        ll f = j - i;
        w0 = (w0 * power(2, f - 1)) % MOD;
 
        if (j < n && a[j] == a[i] + 1) {
            k++;
        }
 
        i = j; 
    }
 
    ll w1 = (k * w0) % MOD;
    ll ans = 0;
 
    if (c > 0) {
        ll wc = power(2, c - 1);
        ans = (wc * (w0 + w1)) % MOD;
    } else {
        ans = w0;
    }
 
    cout << ans << "
";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll t;
    cin >> t;
    while (t--) {
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