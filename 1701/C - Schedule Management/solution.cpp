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
 
bool isPossible(ll mid, vi& cnt) {
    ll left = 0, help = 0;
 
    for (ll i = 1; i < sz(cnt); i++) {
        if (cnt[i] > mid) {
            left += (cnt[i] - mid);
        } else {
            help += (mid - cnt[i]) / 2;
        }
    }
    return help >= left;
}
 
void solve(ll n, vi& a) {
    ll m = sz(a);
    vi cnt(n + 1, 0);
 
    for (ll i = 0; i < m; i++) {
        cnt[a[i]]++;
    }
 
    ll l = 1, h = 2LL * m;
    ll ans = h;
 
    while (l <= h) {
        ll mid = l + (h - l) / 2;
        if (isPossible(mid, cnt)) {
            ans = mid;
            h = mid - 1;
        } else {
            l = mid + 1;
        }
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
 
    while (t--) {
        ll n, m;
        cin >> n >> m;
        vi a(m);
        for (ll i = 0; i < m; i++) {
            cin >> a[i];
        }
        solve(n, a);
    }
 
 
    return 0;
}