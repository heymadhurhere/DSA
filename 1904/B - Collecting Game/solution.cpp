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
 
void solve(vi &v)
{
    vpii arr;
    ll n = sz(v);
    for (ll i = 0; i < n; i++) {
        arr.pb(mp(v[i], i));
    }
    sort(all(arr));
    vi pref(n);
    pref[0] = arr[0].F;
    for (ll i = 1; i < n; i++) {
        pref[i] = pref[i - 1] + arr[i].F;
    }
    vi ans(n);
    for (ll i = 0; i < n; i++) {
        ll j = i;
        ll fnd = i;
        while (j < n) {
            pii p = {pref[j] + 1, LLONG_MIN};
            ll idx = lower_bound(all(arr), p) - arr.begin();
            idx--;
            if (idx == j) break;
            fnd += idx - j;
            j = idx;
        }
        ans[arr[i].S] = fnd;
    }
    for (ll i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vi v(n);
        for (ll i = 0; i < n; i++) {
            cin >> v[i];
        }
        solve(v);
    }
    return 0;
}