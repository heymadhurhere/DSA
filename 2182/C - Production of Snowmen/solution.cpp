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
 
ll solve(vi& a, vi& b, vi& c) {
    set<ll> s1, s2;
 
    ll n = sz(a);
 
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            if (a[i] >= b[j]) {
                ll rel = (j - i + n) % n;
                s1.insert(rel);
            }
        }
    }
 
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            if (b[i] >= c[j]) {
                ll rel = (j - i + n) % n;
                s2.insert(rel);
            }
        }
    }
 
    return n * (n - sz(s1)) * (n - sz(s2));
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vi a(n), b(n), c(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (ll i = 0; i < n; i++) {
            cin >> b[i];
        }
        for (ll i = 0; i < n; i++) {
            cin >> c[i];
        }
        cout << solve(a, b, c) << "
";
    }
}