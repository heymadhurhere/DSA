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
 
void solve(vpii& a) {
    ll n = sz(a);
    if (n == 1){
        cout << "YES
";
        return;
    }
 
    sort(all(a));
 
    ll i = 0, j = 0;
    vector<bool> vis(n, false);
    ll prev = i;
    vis[i] = true;
    
    while (i < n) {
        if (a[i].F > a[prev].S) {
            vis[i] = true;
            prev = i;
        }
        i++;
    }
 
    while (j < n) {
        if (!vis[j]) {
            break;
        }
        j++;
    }
    if (j < n) {
        prev = j;
        vis[j] = true;
        while (j < n) {
            if (!vis[j] && a[j].F > a[prev].S) {
                vis[j] = true;
                prev = j;
            }
            j++;
        }
    }
    
 
    for (ll k = 0; k < n; k++) {
        if (!vis[k]) {
            cout << "NO
";
            return;
        }
    }
    cout << "YES
";
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