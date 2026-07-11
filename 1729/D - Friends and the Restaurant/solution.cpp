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
 
ll solve(vi &expense, vi& budget) {
    ll n = sz(expense);
    vi diff;
    for (ll i = 0; i < n; i++)
    {
        diff.pb(budget[i] - expense[i]);
    }
    sort(all(diff));
    ll i = 0, j = n - 1;
    ll cnt = 0;
    while (i < j) {
        if (diff[i] + diff[j] >= 0) {
            cnt++;
            i++;
            j--;
        }
        else {
            i++;
        }
    }
    return cnt;
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
        vi expense(n), budget(n);
        for (ll i = 0; i < n; i++) {
            cin >> expense[i];
        }
        for (ll i = 0; i < n; i++) {
            cin >> budget[i];
        }
        cout << solve(expense, budget) << "
";
    }
 
    return 0;
}