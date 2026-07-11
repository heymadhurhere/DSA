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
 
vi solve(ll &n) {
    ll bits = log2(n - 1) + 1;
    if (n == 2) {
        bits = 1;
    }
    vi ans;
    ll ul = pow(2, bits - 1);
    ll num = n - 1;
    while (num >= ul) {
        ans.pb(num);
        num--;
    }
    ll i = 0;
    while (i <= num) {
        ans.pb(i);
        i++;
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
        vi result = solve(n);
        for (ll x : result) {
            cout << x << " ";
        }
        cout << '
';
    }
    return 0;
}