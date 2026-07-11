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
 
void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++) {
        cin >> v[i];
    }
 
    ll max_so_far = v[0];
    ll current_sum = v[0];
 
    for (ll i = 1; i < n; i++) {
        if (abs(v[i] % 2) != abs(v[i - 1] % 2)) {
            current_sum = max(v[i], current_sum + v[i]);
        } else {
            current_sum = v[i];
        }
        max_so_far = max(max_so_far, current_sum);
    }
 
    cout << max_so_far << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}