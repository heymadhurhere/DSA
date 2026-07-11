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
 
 
void solve(vi& a, ll k) {
    ll n = sz(a);
 
    ll weeks = n - k + 1;
    ll sum = 0;
 
    ll i = 0, j = n - 1;
 
    while (i <= j) {
        ll mul = min({k, i + 1, weeks});
        if (i == j) {
            sum += mul * a[i];
        } else {
            sum += mul * (a[i] + a[j]);
        }
        i++;
        j--;
    }
    double ans = (double)sum / (double)weeks;
    cout << fixed << setprecision(10) << ans << endl;
    return;
}
 
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll n, k;
    cin >> n >> k;
    vi a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    solve(a, k);
 
    return 0;
}