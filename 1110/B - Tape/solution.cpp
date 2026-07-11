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
 
 
 
void solve(vi& a, ll m, ll k) {
    ll n = sz(a);
    ll total = a[n - 1] - a[0] + 1;
    vi gaps;
 
    for (ll i = 1; i < n; i++) {
        gaps.pb(a[i] - a[i - 1] - 1);
    }
 
    sort(all(gaps));
    reverse(all(gaps));
 
    for (ll i = 0; i < k - 1; i++) {
        total -= gaps[i];
    }
 
    cout << total << endl;
    return;
}
 
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll n, m, k;
    cin >> n >> m >> k;
    vi b(n);
    for (ll i = 0; i < n; i++) {
        cin >> b[i];
    }
    solve(b, m, k);
 
    return 0;
}