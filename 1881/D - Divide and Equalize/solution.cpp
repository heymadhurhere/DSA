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
 
void primeFactorisation(ll n, unordered_map<ll, ll>& mpp) {
    while (n % 2 == 0) {
        mpp[2]++;
        n /= 2;
    }
 
    for (ll i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            mpp[i]++;
            n /= i;
        }
    }
 
    if (n > 1) {
        mpp[n]++;
    }
}
 
 
void solve(vi& a){
    unordered_map<ll, ll> mpp;
    ll n = sz(a);
 
    // ll maxi = *max_element(all(a));
    // ll mini = *min_element(all(a));
 
    // if (maxi == mini) {
    //     cout << "YES" << endl;
    //     return;
    // }
 
    for (ll i = 0; i < n; i++) {
        primeFactorisation(a[i], mpp);
    }
 
    ll sum = 0;
 
    // bool flag = false;
 
    // for (auto it : mpp) {
    //     if (it.S > 1) {
    //         flag = true;
    //         break;
    //     }
    // }
 
    // if (!flag) {
    //     cout << "NO" << endl;
    //     return;
    // }
 
    for (auto it : mpp) {
        if (it.S % n != 0) {
            cout << "NO" << endl;
            return;
        }
    }
 
    if (sum % 2 == 1) {
        cout << "NO" << endl;
        return;
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