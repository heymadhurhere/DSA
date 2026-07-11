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
 
ll solve(vi& a, vi& b, vi& c) {
    ll n = sz(a);
    vector<pair<ll, ll>> mpp1, mpp2, mpp3;
    for (ll i = 0; i < n; i++) {
        mpp1.pb({a[i], i});
        mpp2.pb({b[i], i});
        mpp3.pb({c[i], i});
    }
    sort(all(mpp1), greater<pair<ll, ll>>());
    sort(all(mpp2), greater<pair<ll, ll>>());
    sort(all(mpp3), greater<pair<ll, ll>>());
    ll ans = 0;
    for (ll i = 0; i < 3; i++) {
        for (ll j = 0; j < 3; j++) {
            for (ll k = 0; k < 3; k++) {
                if (mpp1[i].S != mpp2[j].S && mpp2[j].S != mpp3[k].S && mpp1[i].S != mpp3[k].S) {
                    ans = max(ans, mpp1[i].F + mpp2[j].F + mpp3[k].F);
                }
            }
        }
    }
    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
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
    return 0;
}