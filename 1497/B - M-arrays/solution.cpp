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
 
 
void solve(vi& a, ll m){
    ll n = sz(a);
 
    ll cnt = 0;
    map<ll, ll> mpp;
 
    for (ll i = 0; i < n; i++) {
        mpp[a[i] % m]++;
    }
 
    while (!mpp.empty()) {
        ll curr = mpp.begin()->F;
        ll comp = (curr == 0) ? 0 : (m - curr);
 
        if (mpp.find(comp) != mpp.end() && mpp[comp] > mpp[curr]) {
            curr = comp;
        }
        
        ll rem = (curr == 0) ? 0 : (m - curr);
 
        mpp[curr]--;
        if (mpp[curr] == 0) {
            mpp.erase(curr);
        }
 
        while (mpp.find(rem) != mpp.end()) {
            mpp[rem]--;
            if (mpp[rem] == 0) {
                mpp.erase(rem);
            }
            rem = (rem == 0) ? 0 : m - rem;
        }
        cnt++;
    }
    cout << cnt << endl;
    return;
}
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
 
    while (t--) {
        ll n, m;
        cin >> n >> m;
        vi a(n);
 
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
 
        solve(a, m);
    }
 
    return 0;
}