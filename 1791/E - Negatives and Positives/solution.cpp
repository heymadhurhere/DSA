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
 
ll solve(vi& a) {
    ll neg = 0;
    ll sum = 0;
    for (auto& it : a) {
        if (it < 0) neg++;
        sum += abs(it);
        it = abs(it);
    }
    sort(all(a));
    if (neg % 2 == 1) {
        sum -= 2 * a[0];
    } 
    return sum;
}
 
int main() {
    ios_base::sync_with_stdio(false);
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
        cout << solve(a) << "
";
    }
    return 0;
}