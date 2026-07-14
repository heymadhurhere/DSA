#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define all(x) x.begin(), x.end()
#define sz(x) (ll) x.size()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<ll, ll>
#define vpii vector<pii>
 
const int MOD = 1e9 + 7;
const ll INF = 1e18;
 
 
void solve(string s) {
    ll n = sz(s);
    ll cnt = 0;
    ll ans = INT_MIN;
    ll i = 0;
    while (i < n) {
        if (s[i] == '#') {
            cnt++;
            ans = max(ans, cnt);
        } else {
            cnt = 0;
        }
        i++;
    }
    cout << ((ans == INT_MIN) ? 0 : ((ans + 1) / 2)) << endl;
    return;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
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