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
 
 
 
void solve(vi& a, vi& b) {
    ll n = sz(a);
    ll tmp = 0;
    for (ll i = 0; i < n; i++) {
        ll cur = a[i] - tmp;
        if (cur > b[i]) {
            cout << "NO
";
            return;
        }
        tmp = b[i] - cur;
    }
    cout << "YES
";
    return;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
 
    while (t--) {
        ll n;
        cin >> n;
        vi a(n), b(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (ll i = 0; i < n; i++) {
            cin >> b[i];
        }
        solve(a, b);
    }
 
    return 0;
}