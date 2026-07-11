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
 
 
 
void solve(vector<vector<ll>>& a) {
    ll n = sz(a);
    unordered_map<ll, ll> mpp;
 
    for (ll i = 0; i < n; i++) {
        for (ll j = 1; j < sz(a[i]); j++) {
            mpp[a[i][j]]++;
        }
    }
 
    for (ll i = 0; i < n; i++) {
        bool flag = true;
        for (ll j = 1; j < sz(a[i]); j++) {
            if (mpp[a[i][j]] == 1) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << "Yes" << endl;
            return;
        }
    }
 
    cout << "No" << endl;
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
 
        vector<vector<ll>> a;
 
        while (n--) {
            ll k;
            cin >> k;
 
            vi b(k);
            b.pb(k);
 
            for (ll i = 1; i <= k; i++) {
                cin >> b[i];
            }
 
            a.pb(b);
        }
 
        solve(a);
    }
 
    return 0;
}