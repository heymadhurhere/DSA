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
 
void solve(vi& a, vi& x) {
    ll n = sz(a), q = sz(x);
    ll lst = 31;
    for (ll i = 0; i < q; i++){
        if (x[i] >= lst) continue;
        for (ll j = 0; j < n; j++) {
            if (a[j] % (1LL << x[i]) == 0) {
                a[j] += (1LL << x[i]) / 2;
            }
        }
        lst = x[i];
    }  for (ll i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "
";
    return;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll q;
        cin >> q;
        vi a(n), x(q);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (ll i = 0; i < q; i++) {
            cin >> x[i];
        }
        solve(a, x);
    }
    return 0;
}