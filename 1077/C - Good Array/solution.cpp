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
    ll n = sz(a);
 
    ll sum = accumulate(all(a), 0LL);
    map<ll, ll> mpp;
 
    for (ll i = 0; i < n; i++) {
        mpp[a[i]]++;
    }
    vi ans;
 
    for (ll i = 0; i < n; i++) {
        ll newSum = sum - a[i];
        mpp[a[i]]--;
        if (mpp[a[i]] == 0) {
            mpp.erase(a[i]);
        }
        if (newSum % 2 == 0) {
            ll num = newSum / 2;
            if (mpp.find(num) != mpp.end()) {
                ans.pb(i + 1);
            }
        }
        mpp[a[i]]++;
    }
 
    cout << sz(ans) << "
";
 
    for (ll i = 0; i < sz(ans); i++) {
        cout << ans[i] << " ";
    }
    cout << "
";
    return;
}
 
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll n;
    cin >> n;
    vi a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    solve(a);
 
    return 0;
}