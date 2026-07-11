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
 
 
void solve(string s) {
    vi pos;
    ll n = s.length();
 
    for (ll i = 0; i < n; i++) {
        if (s[i] == '*') {
            pos.pb(i);
        }
    }
 
    if (pos.empty() || sz(pos) == 1) {
        cout << 0 << endl;
        return;
    }
 
    ll cnt = sz(pos);
 
    ll cost_left = 0;
    for (ll i = 0; i < cnt; i++) {
        cost_left += abs(pos[i] - i);
    }
 
    ll cost_right = 0;
    for (ll i = 0; i < cnt; i++) {
        cost_right += abs(pos[i] - (n - cnt + i));
    }
 
    ll cost_middle = 0;
    ll mid = cnt / 2;
    ll median = pos[mid];
 
    for (ll i = 0; i < mid; i++) {
        ll tgt = median - (mid - i);
        cost_middle += abs(pos[i] - tgt);
    }
 
    for (ll i = mid; i < cnt; i++) {
        ll tgt_pos = median + i - mid;
        cost_middle += abs(pos[i] - tgt_pos);
    }
 
    ll ans = min({cost_left, cost_right, cost_middle});
    cout << ans << endl;
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
        string s;
        cin >> s;
        solve(s);
    }
    return 0;
}