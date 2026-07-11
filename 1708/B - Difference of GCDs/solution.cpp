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
 
void solve(ll n, ll l, ll r) {
    if (n == 1) {
        cout << "YES" << endl;
        cout << l << endl;
        return;
    }
    vi ans(n);
    ans[0] = l;
    for (ll i = 1; i < n; i++) {
        ll rem = (l % (i + 1));
        ll add = 0;
        if (rem == 0) {
            add = 0;
        } else {
            add = i + 1 - rem;
        }
        ans[i] = l + add;
        if (ans[i] > r) {
            cout << "NO" << endl;
            return;
        }
    }
 
    cout << "YES" << endl;
    for (ll i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
    while (t--) {
        ll n, l, r;
        cin >> n >> l >> r;
        solve(n, l, r);
    }
    return 0;
}