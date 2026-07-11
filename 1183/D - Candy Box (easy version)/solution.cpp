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
        mpp[a[i]]++;
    }
 
    vi tmp;
    for (auto &it : mpp) {
        tmp.pb(it.S);
    }
 
    sort(tmp.rbegin(), tmp.rend());
    ll ans = tmp[0], taken = tmp[0] - 1;
    for (ll i = 1; i < sz(tmp); i++) {
        ans += taken >= 0 ? min(taken, tmp[i]) : 0;
        taken = min(taken, tmp[i]) - 1;
    }
    cout << ans <<"
";
    return;
}
 
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
    while(t--) {
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