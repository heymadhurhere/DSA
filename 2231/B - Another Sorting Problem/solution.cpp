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
 
    vi tmp = a;
    sort(all(tmp));
 
    if (a == tmp) {
        cout << "YES
";
        return;
    }
 
    ll diff = 0;
 
    for (ll i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            diff = max(diff, a[i] - a[i + 1]);
        }
    }
 
    ll p = a[0];
 
    for (ll i = 1; i < n; i++) {
        ll c1 = a[i];
        ll c2 = a[i] + diff;
 
        if (c1 >= p and c2 >= p) {
            p = min(c1, c2);
        } else if (c1 >= p) {
            p = c1;
        } else if (c2 >= p) {
            p = c2;
        } else {
            cout << "NO
";
            return;
        }
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
        vi a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        solve(a);
    }
 
    return 0;
}