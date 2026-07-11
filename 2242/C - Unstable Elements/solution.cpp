#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define all(x) x.begin(), x.end()
#define sz(x) (ll) x.size()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<ll, ll>
#define vpii vector<pii>
 
const int MOD = 1e9 + 7;
 
const ll INF = 1e18;
 
void solve(vi &a, ll k)
{
    map<ll, ll> mpp;
    ll n = sz(a);
    for (ll i = 0; i < n; i++)
    {
        mpp[a[i]]++;
    }
 
    vi freq;
    for (auto &it : mpp)
    {
        freq.pb(it.S);
    }
    sort(all(freq));
    ll m = sz(freq);
    vi suff(m + 1, 0);
    for (ll i = m - 1; i >= 0; i--)
    {
        suff[i] = suff[i + 1] + freq[i];
    }
    ll ans = 0;
 
    for (ll i = 0; i < m; i++)
    {
        if (i > 0 && freq[i] == freq[i - 1])
            continue;
        ll dis = m - i;
        ll sum = suff[i];
        if ((k - sum) % dis == 0)
        {
            ll del = (k - sum) / dis;
            if (freq[i] + del >= 1)
                ans++;
        }
    }
 
    cout << ans << endl;
    return;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vi a(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        solve(a, k);
    }
 
    return 0;
}