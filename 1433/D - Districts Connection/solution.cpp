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
 
 
void solve(vi& a){
    if (*max_element(all(a)) == *min_element(all(a))){
        cout << "NO" << endl;
        return;
    }
 
    cout << "YES" << endl;
    map<ll, ll> mpp;
    for (ll i = 0; i < sz(a); i++) {
        mpp[a[i]]++;
    }
 
    ll min_key = LLONG_MAX, min_freq = LLONG_MAX;
    for (auto it : mpp) {
        if (it.S < min_freq) {
            min_key = it.F;
            min_freq = it.S;
        }
    }
 
    ll center = -1;
    for (ll i = 0; i < sz(a); i++) {
        if (a[i] == min_key) {
            center = i;
            break;
        }
    }
 
    ll elem = -1;
    for (ll i = 0; i < sz(a); i++) {
        if (a[i] != min_key) {
            cout << center + 1 << " " << i + 1 << endl;
            elem = i;
        }
    }
 
    for (ll i = 0; i < sz(a); i++) {
        if (a[i] == min_key && i != center) {
            cout << elem + 1 << " " << i + 1 << endl;
        }
    }
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