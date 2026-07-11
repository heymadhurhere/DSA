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
 
 
ll solve(ll s, ll k, ll m) {
    if (s <= k) {
        ll time = m % k;
        ll ans = max(0LL, s - time);
        return ans;
    } else {
        ll intr = m / k;
        ll time = m % k;
        if (intr % 2 == 0) {
            ll ans = s - time;
            return ans;
        } else {
            ll ans = k - time;
            return ans;
        }
    }
    return 0;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
    while (t--) {
        ll s, k, m;
        cin >> s >> k >> m;
        cout << solve(s, k, m) << "
";
    }
    return 0;
}