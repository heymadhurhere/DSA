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
 
ll solve(vi& a, ll tgt)
{
    ll sum = accumulate(all(a), 0LL);
    if (sum < tgt) return -1;
    if (sum == tgt) return 0;
    ll n = sz(a);
    
    ll l = 0, curr_sum = 0, maxLen = 0;
    
    for (ll r = 0; r < n; r++)
    {
        curr_sum += a[r];
        
        while (curr_sum > tgt)
        {
            curr_sum -= a[l];
            l++;
        }
        
        if (curr_sum == tgt)
        {
            maxLen = max(maxLen, r - l + 1);
        }
    }
    return n - maxLen;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, s;
        cin >> n >> s;
        vi a(n);
        for (ll i = 0; i < n; i++) cin >> a[i];
        cout << solve(a, s) << "
";
    }
 
    return 0;
}