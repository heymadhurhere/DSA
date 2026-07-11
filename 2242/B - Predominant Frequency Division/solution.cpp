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
 
void solve(vi& a)
{
    ll n = sz(a);
    vector<ll> pref1(n), pref2(n);
    ll cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for (ll i = 0; i < n; i++) {
        if (a[i] == 1) cnt1++;
        else if (a[i] == 2) cnt2++;
        else cnt3++;
        
        pref1[i] = cnt1 - cnt2 - cnt3;
        pref2[i] = cnt1 + cnt2 - cnt3;
    }
 
    vector<ll> maxi(n);
    maxi[n - 2] = pref2[n - 2]; 
    for (ll j = n - 3; j >= 0; j--) {
        maxi[j] = max(pref2[j], maxi[j + 1]);
    }
 
 
    for (ll i = 0; i < n - 2; i++) {
        
        if (pref1[i] >= 0) {
            if (maxi[i + 1] >= pref2[i]) {
                cout << "YES
";
                return;
            }
        }
    }
    cout << "NO
";
    return;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
    while (t--)
        {ll n;
        cin >> n;
        vi a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        solve(a);}
    
 
    return 0;
}