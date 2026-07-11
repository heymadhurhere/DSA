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
 
ll factorial(ll n) {
    ll ans = 1;
    for (ll i = 1; i <= n; i++) {
        ans = (ans * i) % MOD;
    }
    return ans;
}
 
 
void solve(vi& a, ll k) {
    ll n = sz(a);
    multiset<ll> ms;
    for (ll i = 0; i < n; i++) {
        if (a[i] % k != 0) {
            ms.insert(k - (a[i] % k));
        }
    }
 
    ll x = 0;
    ll mul = 0;
 
    while (!ms.empty()) {
        ll curr = x - mul * k;
        auto it = ms.lower_bound(curr);
        if (it != ms.end()) {
            ll num = *it;
            ll diff = num - curr;
            x += diff;
            x++;
            ms.erase(it);
        } else {
            mul++;
        }
    }
 
    cout << x << endl;
    return;
}
 
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
 
    while (t--) {
        ll n, k;
        cin >> n >> k;
        vi a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        solve(a, k);
    }
    return 0;
}