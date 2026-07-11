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
 
vi solve(vi &a)
{
    ll n = sz(a);
    vi even, odd;
    for (ll i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
            even.pb(a[i]);
        else
            odd.pb(a[i]);
    }
 
    if (odd.empty())
    {
        vi res(n, 0);
        return res;
    }
 
    sort(even.rbegin(), even.rend());
    sort(odd.rbegin(), odd.rend());
    ll maxim_odd = -1;
    if (!odd.empty())
    {
        maxim_odd = odd[0];
    }
 
    ll even_size = sz(even);
    vi pref(even_size + 1, 0);
    for (ll i = 0; i < even_size; i++)
    {
        pref[i + 1] = pref[i] + even[i];
    }
 
    ll odd_size = sz(odd);
 
    vi ans;
 
    for (ll k = 1; k <= n; k++)
    {
        ll idx = min(even_size, k - 1);
        if ((k - idx) % 2 == 0)
        {
            idx--;
        }
        if (idx >= 0 && (k - idx) <= odd_size)
        {
            ans.pb(pref[idx] + maxim_odd);
        }
        else
        {
            ans.pb(0);
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
        ll n;
        cin >> n;
        vi a(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vi res = solve(a);
        for (ll i = 0; i < n; i++)
        {
            cout << res[i] << (i == n - 1 ? "
" : " ");
        }
    }
 
    return 0;
}