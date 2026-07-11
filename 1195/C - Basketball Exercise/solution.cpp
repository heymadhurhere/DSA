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
 
ll f(vi& a, vi& b, ll idx, ll lastRow, vector<vi>& dp) {
    if (idx >= sz(a)) return 0;
    if (dp[idx][lastRow] != -1) return dp[idx][lastRow];
    ll take1 = LLONG_MIN, take2 = LLONG_MIN, notTake1 = LLONG_MIN, notTake2 = LLONG_MIN;
 
    if (lastRow == 0) {
        take1 = a[idx] + f(a, b, idx + 1, 1, dp);
        take2 = b[idx] + f(a, b, idx + 1, 2, dp);
        notTake1 = f(a, b, idx + 1, lastRow, dp);
        notTake2 = f(a, b, idx + 1, lastRow, dp);
    } else {
        if (lastRow == 1) {
            take2 = b[idx] + f(a, b, idx + 1, 2, dp);
            notTake2 = f(a, b, idx + 1, lastRow, dp);
        } else {
            take1 = a[idx] + f(a, b, idx + 1, 1, dp);
            notTake1 = f(a, b, idx + 1, lastRow, dp);
        }
    }
    return  dp[idx][lastRow] = max({take1, take2, notTake1, notTake2});
}
 
void solve(vi& a, vi& b) {
    ll n = sz(a);
    vector<vi> dp(n + 1, vi(3, -1));
    cout << f(a, b, 0, 0, dp) << endl;
}
 
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll n;
    cin >> n;
    vi a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    vi b(n);
    for (ll i = 0; i < n; i++) {
        cin >> b[i];
    }
    solve(a, b);
 
    return 0;
}