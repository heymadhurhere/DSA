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
 
 
ll solve(vi& a) {
    ll n = a.size();
    ll diff = LLONG_MIN;
    sort(all(a));
    for (ll i = 0; i < n - 1; i+=2) {
        diff = max(diff, abs(a[i] - a[i + 1]));
    }
    return diff;
}
int main()
{
    ios_base::sync_with_stdio(false);
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
        cout << solve(a) << endl;
    }
    return 0;
}
 