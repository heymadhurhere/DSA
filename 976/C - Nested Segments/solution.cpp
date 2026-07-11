#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define all(x) x.begin(), x.end()
#define sz(x) (ll) x.size()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<ll, ll>
#define vpii vector<pii>
 
const int MOD = 1e9 + 7;
 
const ll INF = 1e18;
 
static bool cmp(tuple<ll, ll, ll> a, tuple<ll, ll, ll> b) { 
    if (get<0>(a) != get<0>(b)) {
        return get<0>(a) < get<0>(b);
    } else {
        return get<1>(a) > get<1>(b);
    }
}
void solve(vpii& a) {
    ll n = sz(a);
    vector<tuple<ll, ll, ll>> v;
    for (ll i = 0; i < n; i++) {
        v.pb({a[i].F, a[i].S, i + 1});
    }
 
    sort(all(v), cmp);
    vi min_r(n);
    vi min_id(n);
    min_r[n - 1] = get<1>(v[n - 1]);
    min_id[n - 1] = get<2>(v[n - 1]);
 
    for (ll i = n - 2; i >= 0; i--) {
        if (min_r[i + 1] > get<1>(v[i])) {
            min_r[i] = get<1>(v[i]);
            min_id[i] = get<2>(v[i]);;
        } else {
            min_r[i] = min_r[i + 1];
            min_id[i] = min_id[i + 1];
        }
    }
 
    for (ll i = 0; i < n - 1; i++) {
        if (min_r[i + 1] <= get<1>(v[i])) {
            cout << min_id[i + 1] << " " << get<2>(v[i]) << endl;
            return;
        }
    }
    cout << -1 << " " << -1 << endl;
    return;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll n;
    cin >> n;
    vpii a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i].F >> a[i].S;
    }
    solve(a);
 
    return 0;
}