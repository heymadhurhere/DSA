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
 
 
void solve(vi& a, vpii& queries ){
    ll n = sz(a);
 
    vi leftNearestDifferrent(n);
    leftNearestDifferrent[0] = -1;
 
    for (ll i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) {
            leftNearestDifferrent[i] = i - 1;
        } else {
            leftNearestDifferrent[i] = leftNearestDifferrent[i - 1];
        }
    }
 
    vpii ans;
 
    for (auto& q : queries) {
        ll l = q.F - 1, r = q.S - 1;
 
        if (leftNearestDifferrent[r] < l or leftNearestDifferrent[r] == -1) {
            ans.pb({-1, -1});
            continue;
        } else {
            ans.pb({leftNearestDifferrent[r] + 1, r + 1});
        }
    }
 
    for (auto& p : ans) {
        cout << p.F << " " << p.S << "
";
    }
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
 
        ll q;
        cin >> q;
        vpii queries(q);
        for (ll i = 0; i < q; i++) {
            cin >> queries[i].F >> queries[i].S;
        }
 
        solve(a, queries);
        cout << "
";
    }
 
    return 0;
}