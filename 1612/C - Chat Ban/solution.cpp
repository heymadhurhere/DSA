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
 
 
void solve(ll k, ll x) {
    ll sum = k * (k + 1) / 2;
 
    if (k * k <= x) {
        cout << 2 * k - 1 << endl;
        return;
    }
 
    if (sum == x) {
        cout << k << "
";
        return;
    
    } else if (x < sum) {
        ll l = 1, r = k;
 
        ll ans = -1;
 
        while (l <= r) {
            ll mid = l + (r - l) / 2;
            if (mid * (mid + 1) / 2 >= x) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << ans << "
";
        return;
    } else {
        ll l = 1, r = k - 1;
        ll ans = -1;
        while (l <= r) {
            ll mid = l + (r - l) / 2;
 
            ll omit = k - mid - 1;
            ll emotes = k * k - (omit * (omit + 1) / 2);
            if (emotes >= x) {
                ans = mid + k;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << ans << "
";
        return;
    }
}
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
 
    while (t--) {
        ll k, x;
        cin >> k >> x;
        solve(k, x);
    }
 
    return 0;
}