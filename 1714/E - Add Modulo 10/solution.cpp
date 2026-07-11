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
 
void solve(vi& a) {
    ll n = sz(a);
 
    for (ll i = 0; i < n; i++) {
        while (a[i] % 10 != 2 && a[i] % 10 != 0) {
            ll r = a[i] % 10;
            a[i] += r;
        }
    }
 
    sort(all(a));
    if (a[0] == a[n - 1]) {
        cout << "Yes
";
        return;
    }
 
    for (ll i = 0; i < n - 1; i++) {
        if ((a[i] % 10 == 0 || a[i + 1] % 10 == 0) && a[i] != a[i + 1]) {
            cout << "No
";
            return;
        }
        if ((a[i + 1] - a[i]) % 20 != 0) {
            cout << "No
";
            return;
        }
    }
    cout << "Yes
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
        vi a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        solve(a);
    }
 
 
    return 0;
}