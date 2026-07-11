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
const ll MOD = 1e9 + 7;
 
string solve(vi& a, ll k) {
    set<ll> st;
    for (auto& it : a) {
        st.insert(it);
    }
    for (auto& it :a) {
        if (st.find(it + k) != st.end()) {
            return "YES";
        }
    }
    return "NO";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        vi a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << solve(a, k) << "
";
    }
    return 0;
}