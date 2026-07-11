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
 
ll solve(vi& a, ll coins) {
    ll n = sz(a);
    vector<pair<ll, pair<ll, ll>>> mpp;
    for (ll i = 0; i < n; i++) {
        mpp.pb({a[i] + i + 1, {a[i], i + 1}});
    }
    ll cnt = 0;
    sort(all(mpp));
    for (ll i = 0; i < n; i++) {
        if (coins >= mpp[i].F) {
            coins -= mpp[i].F;
            cnt++;
        }
    }
    return cnt;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
    while (t--) {
        ll n, coins;
        cin >> n >> coins;
        vi a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << solve(a, coins) << "
";
    }
    return 0;
}