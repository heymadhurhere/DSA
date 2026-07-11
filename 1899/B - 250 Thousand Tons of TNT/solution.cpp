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
 
void solve(vi& arr) {
    ll n = arr.size();
    ll diff = LLONG_MIN, maxi = LLONG_MIN, mini = LLONG_MAX;
    vi pref(n);
    pref[0] = arr[0];
    for (ll i = 1; i < n; i++) {
        pref[i] = pref[i - 1] + arr[i];
    }
    for (ll i = 1; i <= n; i++) {
        if (n % i == 0) {
            maxi = pref[i - 1];
            mini = pref[i - 1];
            for (ll j = 2 * i - 1; j < n; j += i) {
                maxi = max(maxi, pref[j] - pref[j - i]);
                mini = min(mini, pref[j] - pref[j - i]);
            }
            diff = max(diff, maxi - mini);
        }
    }
    cout << diff << endl;
    return;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vi arr(n);
        for (ll i = 0; i < n; i++) {
            cin >> arr[i];
        }
        solve(arr);
    }
    return 0;
}