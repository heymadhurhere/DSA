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
 
ll f(ll idx, ll a, ll b, vi &arr, vi &dp) {
    if (idx >= sz(arr))
        return 0;
    if (dp[idx] != -1)
        return dp[idx];
    
    ll conq = (arr[idx] - arr[idx - 1]) * b * (sz(arr) - idx) + f(idx + 1, a, b, arr, dp);
    ll mov_and_conq = (arr[idx] - arr[idx - 1]) * (a + b) + f(idx + 1, a, b, arr, dp);
    return dp[idx] = min(conq, mov_and_conq);
}
 
void solve(vi arr, ll a, ll b) {
    ll n = sz(arr);
    vi dp(n + 1, -1);
    arr.insert(arr.begin(), 0);
    cout << f(1, a, b, arr, dp) << endl;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, a, b;
        cin >> n >> a >> b;
        vi arr(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        solve(arr, a, b);
    }
 
    return 0;
}