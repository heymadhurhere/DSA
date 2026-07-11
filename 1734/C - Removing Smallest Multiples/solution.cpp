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
 
ll solve(vi &a)
{
    ll n = sz(a);
    ll cost = 0;
    vi tmp;
    for (ll i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            tmp.pb(i + 1);
        }
    }
    if (sz(tmp) == 0)
    {
        return 0;
    }
    vector<bool> used (n + 1, false);
    unordered_set<ll> st (all(tmp));
    
    ll new_sz = sz(tmp);
    for (ll i = 0; i < new_sz; i++) {
        ll x = tmp[i];
        for (ll j = tmp[i]; j <= n; j += tmp[i]) {
            if (used[j] && st.find(j) == st.end()) {
                continue;
            }
            else if (st.find(j) != st.end()) {
                used[j] = true;
                cost += x;
                st.erase(j);
            }
            else if (st.find(j) == st.end()) {
                break;
            }
        }
    }
    return cost;
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
        string s;
        cin >> s;
        vi a(n);
        for (ll i = 0; i < n; i++)
        {
            a[i] = s[i] - '0';
        }
        cout << solve(a) << "
";
    }
 
    return 0;
}