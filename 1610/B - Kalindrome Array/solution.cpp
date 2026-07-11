#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<long long, long long>
#define vi vector<long long>
#define vpii vector<pii>
#define all(x) x.begin(), x.end()
#define sz(x) (ll)(x).size()
#define F first
#define S second
const ll MOD = 1e9 + 7;
 
bool f(vi& a, ll x) {
    ll n = sz(a);
    vi b;
    for (ll i = 0; i < n; i++) {
        if (a[i] != x) {
            b.push_back(a[i]);
        }
    }
    ll m = sz(b);
    for (ll i = 0; i < m; i++) {
        if (b[i] != b[m - i - 1]) {
            return false;
        }
    }
    return true;
}
 
string solve(vi& a) {
    ll n = sz(a);
    for (ll i = 0; i < n; i++) {
        if (a[i] != a[n - i - 1]) {
            if (f(a, a[i]) || f(a, a[n - i -1])) {
                return "YES";
            }
            else {
                return "NO";
            }
        }
    }
    return "YES";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vi a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << solve(a) << "
";
    }
    return 0;
}