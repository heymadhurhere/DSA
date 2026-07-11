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
    unordered_map<ll, ll> mpp;
 
    for (ll i = 0; i < n; i++) {
        ll diff = a[i] - (i + 1);
        if (mpp.find(diff) != mpp.end()) {
            mpp[diff] += a[i];
        } else {
            mpp[diff] = a[i];
        }
    }
 
    ll ans = LLONG_MIN;
    for (auto it : mpp) {
        ans = max(ans, it.S);
    }
    cout << ans << "
";
    return;
}
 
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll n;
    cin >> n;
    vi a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    solve(a);
 
    return 0;
}