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
 
 
void solve(vi& a, ll k) {
    ll n = sz(a);
    if (k >= 3) {
        cout << 0 << "
";
        return;
    }
    vi diff;
    for (ll i = 0; i < n; i++) {
        for (ll j = i + 1; j < n; j++) {
            if (abs(a[i] - a[j]) == 0) {
                cout << 0 << "
";
                return;
            }
            diff.pb(abs(a[i] - a[j]));
        }
    }
 
    ll ans = LLONG_MAX;
 
    ans = *min_element(all(diff));
    ll mini = *min_element(all(a));
    ans = min(ans, mini);
 
    if (k == 1) {
        cout << ans << "
";
        return;
    }
 
    sort(all(a));
 
    for (ll i = 0; i < sz(diff); i++) {
        auto it = lower_bound(all(a), diff[i]);
        ll tmp = -1;
        if (*it == diff[i]) {
            cout << 0 << "
";
            return;
        }
        if (it != a.begin()) {
            ans = min({ans, abs(diff[i] - *(it - 1)), abs(diff[i] - *it)});
        }
        else {
            ans = min({ans, abs(diff[i] - *it)});
        }
    }
    cout << ans << "
";
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