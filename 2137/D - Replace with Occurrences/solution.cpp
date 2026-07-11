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
    unordered_map<ll, ll> freq;
    ll n = sz(a);
    for (ll x : a) {
        freq[x]++;
    }
 
    for (auto &p : freq) {
        if (p.S % p.F != 0) {
            cout << -1 << "
";
            return;
        }
    }
 
    vi ans(n);
 
    map<ll, ll> current_id;
    map<ll, ll> seen;
    ll id = 1;
 
    for (ll i = 0; i < n; i++) {
        ll req = a[i];
        
        if (seen[req] % req == 0) {
            current_id[req] = id++;
        }
        
        ans[i] = current_id[req];
        seen[req]++;
    }
 
    for (ll x : ans) {
        cout << x << " ";
    }
    cout << "
";
    return;
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