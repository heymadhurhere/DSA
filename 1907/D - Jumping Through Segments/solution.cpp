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
 
bool isPossible(vpii& a, ll mid) {
    ll left = 0;
    ll right = 0;
 
    for (ll i = 0; i < sz(a); i++) {
        left = left - mid;
        right = right + mid;
        if (a[i].S < left || a[i].F > right) {
            return false;
        }
 
        left = max(left, a[i].F);
        right = min(right, a[i].S);
    }
    return true;
}
 
void solve(vpii& a) {
    ll n = sz(a);
 
    ll l = 0, r = LLONG_MIN;
 
    for (ll i = 0; i < n; i++) {
        r = max(r, a[i].S);
    }
 
    ll ans = r;
    while (l < r) {
        ll mid = l + (r - l) / 2;
        if (isPossible(a, mid)) {
            ans = mid;
            r = mid;
        } else {
            l = mid + 1;
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
        ll n;
        cin >> n;
        vpii a(n);
 
        for (ll i = 0; i < n; i++) {
            cin >> a[i].F >> a[i].S;
        }
 
        solve(a);
    }
 
    return 0;
}