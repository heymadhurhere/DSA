#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<long long, long long>
#define vi vector<long long>
#define vpii vector<pii>
#define all(x) x.begin(), x.end()
#define sz(x) (ll)(x).size()
#define F first
#define S second
const ll MOD = 1e9 + 7;
 
ll solve(vi& a) {
    ll n = sz(a);
    vi pref(n), suff(n);
    for (ll i = 0; i < n; i++) {
        pref[i] = (i == 0 ? 0 : pref[i - 1]) + a[i];
    }
    for (ll i = n - 1; i >= 0; i--) {
        suff[i] = (i == n - 1 ? 0 : suff[i + 1]) + a[i];
    }
    ll i = 0, j = n - 1, cnt = 0;
    while (i < j) {
        if (pref[i] == suff[j]) {
            cnt = max(cnt, i + 1 + n - j);
            i++;
        }
        if (pref[i] > suff[j] && i < j) {
            j--;
        }
        else if (pref[i] < suff[j] && i < j) {
            i++;
        }
    }
    return cnt;
}
 
int main() {
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
        cout << solve(a) << "
";
    }
    return 0;
}