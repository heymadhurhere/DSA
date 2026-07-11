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
 
 
void solve(ll n) {
    if (n % 2 == 0) {
        cout << ((n / 2) + 1) * ((n / 2) + 1) << endl;
        return;
    } else {
        cout << ((n / 2) + 2) * ((n / 2) + 1) * 2 << endl;
        return;
    }
}
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll n;
    cin >> n;
    solve(n);
 
    return 0;
}