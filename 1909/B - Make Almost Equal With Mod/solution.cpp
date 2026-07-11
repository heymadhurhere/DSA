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
 
 
void solve(vi& a) {
    ll n = sz(a);
 
    if (n == 2) {
        cout << (ll)1e18 << "
";
        return;
    }
 
    ll cnt_e = 0, cnt_o = 0;
 
    for (ll i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            cnt_e++;
        } else {
            cnt_o++;
        }
    }
 
    if (cnt_e == n or cnt_o == n) {
        ll k = 2;
        while (true) {
            set<ll> rem;
 
            for (ll i = 0; i < n; i++) {
                rem.insert(a[i] % k);
            }
 
            if (sz(rem) == 2) {
                cout << k << "
";
                return;
            }
 
            k *= 2;
        }
    }
 
    else {
        cout << 2 << "
";
        return;
    }
 
 
}
 
int main()
{
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
        solve(a);
    }
 
    return 0;
}