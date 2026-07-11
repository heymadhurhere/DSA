#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<ll, ll>
#define vi vector<ll>
#define vpii vector<pii>
#define all(x) x.begin(), x.end()
#define sz(x) (ll)(x).size()
#define F first
#define S second
 
ll solve(vi& a, ll idx, vi& dp) {
    if (idx >= sz(a)) return 0;
    if (dp[idx] != -1) return dp[idx];
    ll take = (idx + a[idx] < sz(a)) ? solve(a, idx + a[idx] + 1, dp) : LLONG_MAX;
    ll notTake = 1 + solve(a, idx + 1, dp);
    return dp[idx] = min(take, notTake);
}
 
void res(vi& a) {
    ll n = sz(a);
    vi dp(n, -1);
    cout << solve(a, 0, dp) << endl;
    return;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
 
    while (t--) {
        ll n;
        cin >> n;
 
        vi a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        res(a);
    }
 
    return 0;
}