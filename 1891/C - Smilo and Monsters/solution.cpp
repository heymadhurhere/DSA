#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<ll, ll>
#define vi vector<ll>
#define vpii vector<pii>
#define all(x) x.begin(), x.end()
#define sz(x) (ll)(x).size()
#define F first
#define S second
 
void solve(vi& a) {
    ll n = sz(a);
    sort(all(a));
    ll l = 0, r = n - 1;
    ll ans = 0, x = 0;
    while (l <= r) {
        if (l == r) {
            
            ll y = (a[r] - x + 1) / 2;
            ans += y;
            if (a[r] - y > 0) ans++;
            break;
        } else if (a[r] <= x) {
            ans += 1;
            x = 0;
            r--;
        } else if (x + a[l] >= a[r]) {
            ll need = a[r] - x;
            ans += need;
            x +=  need;
            a[l] -= need;
        } else {
            ans += a[l];
            x += a[l];
            l++;
        }
    }
    cout << ans << endl;
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
 
        vi a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        solve(a);
    }
 
    return 0;
}