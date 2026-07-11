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
    string tmp = "";
    ll n = sz(s);
    ll i = 0;
    while (i < n) {
        if (s[i] == 'a' || s[i] == 'b') {
            tmp += s[i];
        }
        i++;
    }
 
    vi cnt;
    i = 0;
    ll p = 0;
    while (i < n) {
        if (s[i] == 'a') {
            p++;
        } else if (s[i] == 'b') {
            if (p != 0) {
                cnt.pb(p + 1);
            }
            p = 0;
        }
        i++;
    }
    if (p != 0) {
        cnt.pb(p + 1);
    }
    if (cnt.empty()) {
        cout << 0 << endl;
        return;
    }
    if (sz(cnt) == 1) {
        cout << cnt[0] - 1 << endl;
        return;
    }
    ll ans = 1;
    for (ll i = 0; i < sz(cnt); i++) {
        ans = (ans * cnt[i]) % MOD;
    }
    ans--;
    cout << ans << endl;
    return;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    string s;
    cin >> s;
    solve(s);
 
    return 0;
}