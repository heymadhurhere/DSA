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
 
 
void solve(vi& a, ll wid) {
    ll n = sz(a);
 
    multiset<ll> ms;
 
    for (ll i = 0; i < n; i++) {
        ms.insert(a[i]);
    }
 
    ll cnt = 0;
 
    while (!ms.empty()) {
        cnt++;
        ll space = wid;
        while (!ms.empty()) {
            auto it = ms.upper_bound(space);
 
            if (it == ms.begin()) {
                break;
            }
 
            it--;
            space -= *it;
            ms.erase(it);
        }
    }
    cout << cnt << endl;
    return;
}
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
 
    while (t--) {
        ll n, w;
        cin >> n >> w;
        vi a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        solve(a, w);
    }
 
    return 0;
}