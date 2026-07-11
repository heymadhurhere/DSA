#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void f(vector<ll> &b, ll k);
 
 
int main()
 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll test;
    cin >> test;
    while (test--)
    {
        ll p, k;
        cin >> p >> k;
        vector<ll> b(p);
        for (auto &it : b)
        {
            cin >> it;
        }
        f(b, k);
    }
    return 0;
 
}
 
void f(vector<ll> &b, ll k)
 
{
 
    ll p = b.size();
    ll ptr = 0;
    ll ans = 0;
    ll sz = 0;
    while (ptr < p)
    {
        if (b[ptr] == 0)
            sz++;
        if (sz == k){
            ans++;
            ptr++;
            sz = 0;
        }
        if (sz < k && b[ptr] == 1) {
            sz = 0;
        }
        ptr++;
    }
    cout << ans << endl;
    return;
}