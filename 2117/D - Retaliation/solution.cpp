#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
string canExplodeArray(const vector<ll> &a)
{
    int n = a.size();
 
    if (n == 1)
    {
        return "YES";
    }
 
    ll denom = 1LL * n * n - 1;
    ll num_x = 1LL * n * a[n - 1] - a[0];
    ll num_y = 1LL * n * a[0] - a[n - 1];
 
    if (num_x < 0 || num_y < 0 || num_x % denom != 0 || num_y % denom != 0)
    {
        return "NO";
    }
 
    ll x = num_x / denom;
    ll y = num_y / denom;
 
    for (int i = 0; i < n; ++i)
    {
        ll val = x * (i + 1) + y * (n - i);
        if (a[i] != val)
        {
            return "NO";
        }
    }
 
    return "YES";
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        cout << canExplodeArray(a) << endl;
    }
 
    return 0;
}