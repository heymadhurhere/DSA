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
 
    ll yaseer = accumulate(all(a), 0LL);
 
    map<ll, ll> mpp;
    mpp[0] = 1;
    ll sum = 0;
    for (ll i = 0; i < n; i++) {
        sum += a[i];
        if (i == n - 1) {
            mpp[0]--;
            if (mpp[0] == 0) {
                mpp.erase(0);
            }
        }
        ll rem = sum - yaseer;
        if (!mpp.empty() && mpp.begin()->first <= rem) {
            cout << "NO" << endl;
            return;
        }
        mpp[sum]++;
    }
    cout << "YES" << endl;
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
        vi a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
 
        solve(a);
    }
 
    return 0;
}