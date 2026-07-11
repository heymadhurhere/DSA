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
 
vi solve(ll n) {
    vi ans;
    if (n == 2) {
        return {-1, 2};
    }
    if (n % 2 == 1) {
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                ans.pb(-1);
            } else {
                ans.pb(3);
            }
        }
    } else {
        for (int i = 0; i < n - 2; i++) {
            if (i % 2 == 0) {
                ans.pb(-1);
            } else {
                ans.pb(3);
            }
        }
        ans.pb(-1);
        ans.pb(2);
    }
    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vi ans = solve(n);
        for (ll i = 0; i < sz(ans); i++) {
            cout << ans[i] << " ";
        }
        cout << "
";
    }
    return 0;
}