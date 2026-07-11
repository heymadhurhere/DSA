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
 
 
vi solve(vi & a, vi & b) {
    ll n = sz(a);
    ll k = sz(b);
    vi pref(n);
    pref[0] = a[0];
    for (ll i = 1; i < n; i++) {
        pref[i] = pref[i - 1] + a[i];
    }
    vi maxi(n);
    maxi[0] = a[0];
    for (ll i = 1; i < n; i++) {
        maxi[i] = max(maxi[i - 1], a[i]);
    }
    
    vi ans;
    for (ll x : b) {
        if (x < maxi[0]) {
            ans.pb(0);
            continue;
        }
        auto it = upper_bound(all(maxi), x);
        ll idx = it - maxi.begin() - 1;
        ans.pb(pref[idx]);
    }
    return ans;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, q;
        cin >> n >> q;
        vi a(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vi b(q);
        for (ll i = 0; i < q; i++)
        {
            cin >> b[i];
        }
        vi ans = solve(a, b);
        for (ll i = 0; i < q; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "
";
    }
    
    return 0;
}
 