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
 
bool check(vi a, vi b, ll mid) {
    for (ll i = 0; i < mid; i++) {
        a.pop_back();
        b.pop_back();
    }
 
    reverse(all(b));
 
    for (ll i = 0; i < sz(a); i++) {
        if (a[i] >= b[i])
            return false;
    }
    return true;
}
 
void solve(vi& a, vi& b, ll m) {
    ll n = sz(b);
    vi tmp(n);
    tmp[0] = 1;
 
    for (ll i = 0; i < n - 1; i++) {
        tmp[i + 1] = a[i];
    }
 
    sort(all(tmp));
    sort(all(b));
    reverse(all(b));
 
    ll l = 0, h = n;
 
    while (l < h) {
        ll mid = (l + h) / 2;
        if (check(tmp, b, mid)) {
            h = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << "
";
    return;
}
 
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
 
    while (t--) {
        ll n, m;
        cin >> n >> m;
 
        vi a(n - 1), b(n);
        for (ll i = 0; i < n - 1; i++) {
            cin >> a[i];
        }
        for (ll i = 0; i < n; i++) {
            cin >> b[i];
        }
 
        solve(a, b, m);
    }
 
 
    return 0;
}