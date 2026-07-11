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
 
ll calcWater(vi& arr, ll h) {
    ll sum = 0;
    ll n = sz(arr);
    for (ll i = 0; i < n; i++) {
        if (arr[i] < h) {
            sum += h - arr[i];
        }
    }
    return sum;
}
 
ll solve(vi& arr, ll x) {
    ll low = 1, high = 1e12, ans = -1;
    while (low <= high) {
        ll mid = low + (high - low) / 2;
        if (calcWater(arr, mid) <= x) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
    while (t--) {
        ll n, c;
        cin >> n >> c;
        vi arr(n);
        for (ll i = 0; i < n; i++) cin >> arr[i];
        cout << solve(arr, c) << "
";
    }
}