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
 
ll solve(vi& arr, ll c) {
    __int128 sqSum = 0, sum = 0;
    ll n = sz(arr);
    for (ll x : arr) {
        sum += x;
        sqSum += (__int128)x * x;
    }
 
    long double A = n;
    long double B = sum;
    long double C = ((long double)sqSum - (long double)c) / 4.0L;
 
    long double D = B * B - 4.0L * A * C;
    long double w = (-B + sqrt(D)) / (2.0L * A);
 
    return (ll)llround(w);
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