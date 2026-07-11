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
const ll MOD = 1e9 + 7;
 
bool customSort(const pair<long long, pair<long, long>> &a,
                const pair<long long, pair<long, long>> &b) {
    if (a.first != b.first) return a.first > b.first; // sort by first element
    if (a.second.first != b.second.first) return a.second.first < b.second.first; // sort by inner first
    return a.second.second < b.second.second; // sort by inner second
}
 
void solve(vi& a, vi& b) {
    ll n = sz(a);
    ll i = 0, j = 1;
    vector<pair<ll, pii>> mpp;
    while (j < n) {
        if (b[j] >= b[j - 1]) {
            if (j + 1 >= n) {
                mpp.pb({j - i + 1, {i + 1, j + 1}});
                break;
            }
            j++;
        }
        else {
            mpp.pb({j - i, {i + 1, j}});
            i = j;
            j++;
        }
    }
    sort(mpp.begin(), mpp.end(), customSort);
    // sort(all(mpp), greater<pair<ll, pii>>());
    for (auto& it : mpp) {
        ll left = it.S.first;
        ll right = it.S.second;
        bool ok = false;
        for (ll i = left - 1; i < right; i++) {
            if (a[i] != b[i]) {
                ok = true;
                break;
            }
        }
        if (ok) {
            map<ll, ll> mpp1, mpp2;
            for (ll k = left - 1; k < right; k++) {
                mpp1[a[k]]++;
            }
            for (ll k = left - 1; k < right; k++) {
                mpp2[b[k]]++;
            }
            if (mpp1 == mpp2) {
                cout << left << " " << right << "
";
                return;
            }}
        }
    }
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vi a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        solve(a, b);
    }
    return 0;
}