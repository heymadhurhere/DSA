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
 
ll solve(ll a, ll b) {
    ll a_top = a;
    ll cnt_a_top = 0;
 
    ll i = 1;
    while (a_top >= i) {
        a_top -= i;
        cnt_a_top++;
        i *= 4;
    }
 
    i = 2;
    ll b_second = b;
    ll cnt_b_second = 0;
 
    i = 2;
    while (b_second >= i) {
        b_second -= i;
        cnt_b_second++;
        i *= 4;
    }
 
    ll ans1 = 0;
 
    
    if (cnt_a_top == cnt_b_second) {
        ans1 = 2 * cnt_a_top;
    } else if (cnt_a_top > cnt_b_second) {
        ans1 = cnt_b_second + cnt_b_second + 1;
    } else {
        ans1 = cnt_a_top + cnt_a_top;
 
    }
 
    ll b_top = b;
    ll cnt_b_top = 0;
 
    i = 1;
    while (b_top >= i) {
        b_top -= i;
        cnt_b_top++;
        i *= 4;
    }
 
    i = 2;
    ll a_second = a;
    ll cnt_a_second = 0;
 
    i = 2;
    while (a_second >= i) {
        a_second -= i;
        cnt_a_second++;
        i *= 4;
    }
 
    ll ans2 = 0;
 
    if (cnt_b_top == cnt_a_second) {
        ans2 = 2 * cnt_b_top;
    } else if (cnt_b_top > cnt_a_second) {
        ans2 = cnt_a_second + cnt_a_second + 1;
    } else {
        ans2 = cnt_b_top + cnt_b_top;
    }
 
    return max(ans1, ans2);
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;
        cout << solve(a, b) << "
";
    
    }
}