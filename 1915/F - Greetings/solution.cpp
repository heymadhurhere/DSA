#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<ll, ll>
#define vi vector<ll>
#define vpii vector<pii>
#define all(x) x.begin(), x.end()
#define sz(x) (ll)(x).size()
#define F first
#define S second
 
ll mergeAndCount(vector<ll>& arr, ll l, ll m, ll r) {
        vector<ll> left(arr.begin() + l, arr.begin() + m + 1);
        vector<ll> right(arr.begin() + m + 1, arr.begin() + r + 1);
        
        ll i = 0, j = 0, k = l;
        ll cnt = 0;
        
        while (i < left.size() && j < right.size()) {
            if (left[i] <= right[j]) {
                arr[k++] = left[i++];
            } else {
                arr[k++] = right[j++];
                cnt += (left.size() - i);
            }
        }
        while (i < left.size()) arr[k++] = left[i++];
        while (j < right.size()) arr[k++] = right[j++];
        
        return cnt;
    }
 
ll mergeSortAndCount(vector<ll>& arr, ll l, ll r) {
    ll cnt = 0;
    if (l < r) {
        ll m = l + (r - l) / 2;
        cnt += mergeSortAndCount(arr, l, m);
        cnt += mergeSortAndCount(arr, m + 1, r);
        cnt += mergeAndCount(arr, l, m, r);
    }
    return cnt;
}
void solve(vpii& a) {
    ll n = sz(a);
    sort(all(a));
 
    vi ans(n);
 
    for (ll i = 0; i < n; i++) {
        ans[i] = a[i].S;
    }
 
    cout << mergeSortAndCount(ans, 0, sz(ans) - 1) << endl;
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
 
        vpii a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i].F >> a[i].S;
        }
        solve(a);
    }
 
    return 0;
}