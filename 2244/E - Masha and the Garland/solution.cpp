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
 
 
void solve(string s, ll q) {
    string tgt1 = "1", tgt2 = "0";
    ll n = sz(s);
    for (ll i = 1; i < n; i++) {
        tgt1 += (tgt1[i - 1] == '0' ? '1' : '0');
        tgt2 += (tgt2[i - 1] == '1' ? '0' : '1');
    }
 
    vi mis1(n, 0), mis2(n, 0);
    for (ll i = 0; i < n; i++) {
        if (s[i] != tgt1[i]) {
            mis1[i] = 1;
        }
        if (s[i] != tgt2[i]) {
            mis2[i] = 1;
        }
    }
 
    vi pref1(n, 0), pref2(n, 0);
    pref1[0] = mis1[0];
    pref2[0] = mis2[0];
    for (ll i = 1; i < n; i++) {
        pref1[i] = pref1[i - 1];
        if (mis1[i] == 1 && mis1[i - 1] == 0) {
            pref1[i]++;
        }
        pref2[i] = pref2[i - 1];
        if (mis2[i] == 1 && mis2[i - 1] == 0) {
            pref2[i]++;
        }
    }
 
    while (q--) {
        ll l, r, k;
        cin >> l >> r >> k;
        l--, r--;
        ll f1 = 0;
        if (mis1[l] == 1) {
            f1 += 1;
        }
        if (l < r) {
            f1 += pref1[r] - pref1[l];
        }
        ll f2 = 0;
        if (mis2[l] == 1) {
            f2 += 1;
        }
        if (l < r) {
            f2 += pref2[r] - pref2[l];
        }
        if (f1 <= k || f2 <= k) {
            cout << "YES
";
            //return;
        } else {
            cout << "NO
";
            //return;
        }
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll t;
    cin >> t;
    while (t--) {
        ll n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        solve(s, q);
    }
    return 0;
}