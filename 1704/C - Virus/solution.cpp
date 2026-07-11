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
// const ll MOD = 1e9 + 7;
 
ll solve(vi& house, ll n) {
    sort(all(house));
    ll m = sz(house);
    vi sgmt;
 
    if (m == n) return n;
 
    for (ll i = 1; i < m; i++) {
        sgmt.pb(house[i] - house[i - 1] - 1);
    }
    sgmt.pb(n - house[m - 1] + house[0] - 1);
    sort(sgmt.rbegin(), sgmt.rend());
 
    ll days = 0, saved = 0;
    
    for (ll i = 0; i < sgmt.size(); i++) {
        ll curr = sgmt[i] - days * 2;
        if (curr > 0) {
            saved++;
 
            curr -= 2;
            if (curr > 0) {
                saved += curr;
            }
            days += 2;
        }
    }
    return n - saved;
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
        vi house(m);
        for (ll i = 0; i < m; i++) {
            cin >> house[i];
        }
        cout << solve(house, n) << "
";
    }
 
    return 0;
}