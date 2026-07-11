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
 
void solve(ll n) {
    vi factors;
 
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            factors.pb(i);
            if (i * i != n) {
                factors.pb(n / i);
            }
        }
    }
 
    set<ll> st;
 
    for (ll i = 0; i < sz(factors); i++) {
        st.insert(factors[i]);
    }
 
    if (sz(st) < 5) {
        cout << "NO
";
        return;
    }
 
    auto it = st.begin();
    it++;
    ll a = *it;
    it++;
    ll b = *it;
    
    while (it != st.end() and n % (a * b) != 0) {
        it++;
        if (it != st.end()) {
            b = *it;
        }
    }
 
    if (it == st.end()) {
        cout << "NO
";
        return;
    }
 
    ll c = n / (a * b);
 
    if (a != b and b != c and a != c) {
        cout << "YES
";
        cout << a << " " << b << " " << c << "
";
        return;
    }
 
    cout << "NO
";
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
        solve(n);
    }
 
    return 0;
}