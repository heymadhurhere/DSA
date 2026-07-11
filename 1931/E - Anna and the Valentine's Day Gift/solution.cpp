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
 
void solve(vi& a, ll m) {
    ll n = sz(a);
 
    vi zeros;
    for (ll i = 0; i < n; i++) {
        ll num = a[i];
        ll cnt = 0;
        while (num % 10 == 0) {
            num /= 10;
            cnt++;
        }
        zeros.pb(cnt);
    }
    sort(all(zeros));
    reverse(all(zeros));
 
    ll cntDig = 0;
    for (ll i = 0; i < n; i++) {
        cntDig += log10(a[i]) + 1;
    }
 
    ll remove = 0;
    ll i = 0;
    while (i < n) {
        remove += zeros[i];
        i += 2;
    }
 
    if (cntDig - remove >= m + 1) {
        cout << "Sasha
";
        return;
    }
    cout << "Anna
";
    return;
}
 
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
 
    while (t--) {
        ll n, m;
        cin >> n >> m;
        vi a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        solve(a, m);
    }
 
    return 0;
}