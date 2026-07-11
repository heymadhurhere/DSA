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
 
ll solve(vector<vi>& a) {
    ll n = sz(a);
    ll m = sz(a[0]);
    ll ans = 0;
    for (ll col = 0; col < m; col++) {
        vi tmp;
        for (ll row = 0; row < n; row++) {
            tmp.pb(a[row][col]);
        }
        sort(all(tmp));
        reverse(all(tmp));
        vi suffix_sum(n, 0);
        suffix_sum[n - 1] = tmp[n - 1];
        for (ll i = n - 2; i >= 0; i--) {
            suffix_sum[i] = suffix_sum[i + 1] + tmp[i];
        }
        for (ll i = 0; i < n; i++) {
            if (i + 1 < n) {
            ans += tmp[i] * (n - i - 1) - suffix_sum[i + 1];
            }
        }
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
        ll n, m;
        cin >> n >> m;
        vector<vi> a;
        for (ll i = 0; i < n; i++) {
            vi temp;
            for (ll j = 0; j < m; j++) {
                ll x;
                cin >> x;
                temp.pb(x);
            }
            a.pb(temp);
        }
        cout << solve(a) << "
";
    }
    
    return 0;
}
 