#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()
 
 
void solve(vi& a, vi& b) {
    ll n = sz(a);
    vi pref(n, 0);
    pref[0] = b[0];
    for (ll i = 1; i < n; i++) {
        pref[i] = pref[i - 1] + b[i];
    }
 
    vi suff(n, 0);
    suff[n - 1] = b[n - 1];
    for (ll i = n - 2; i >= 0; i--) {
        suff[i] = suff[i + 1] + b[i];
    }
 
    vi ans(n, 0);
    vi partial(n + 1, 0);
    vi full(n + 1, 0);
    for (ll i = 0; i < n; i++) {
        if (suff[i] <= a[i]) {
            full[i]++;
            full[n]--;
        } else {
            ll l = i, h = n - 1, idx = i - 1;
            ll sum = (i > 0) ? pref[i - 1] : 0;
            while (l <= h) {
                ll mid = l + (h - l) / 2;
                ll range = pref[mid] - sum;
                if (range <= a[i]) {
                    idx = mid;
                    l = mid + 1;
                } else {
                    h = mid - 1;
                }
            }
            if (idx >= i) {
                full[i]++;
                full[idx + 1]--;
            }
            if (idx + 1 < n) {
                ll consumed = (idx >= i) ? (pref[idx] - sum) : 0;
                ll remaining = a[i] - consumed;
                partial[idx + 1] += remaining;
            }
        }
    }
 
    ll cnt = 0;
    for (ll i = 0; i < n; i++) {
        cnt += full[i];
        ans[i] = (cnt * b[i]) + partial[i];
        cout << ans[i] << " ";
    }
    cout << endl;
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
        vi a(n), b(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (ll i = 0; i < n; i++) {
            cin >> b[i];
        }
        solve(a, b);
    }
 
    return 0;
}