#include <bits/stdc++.h>
using namespace std;
 
bool minm(long long l1, long long h1, long long l2, long long h2)
{
    return h1 >= l2 - 1 && h2 >= l1 - 1;
}
 
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
 
    for (int i = 0; i < n - 1; ++i)
    {
        if (abs(a[i] - a[i + 1]) <= 1)
        {
            cout << 0 << endl;
            return;
        }
    }
 
    int ans = n;
    for (int p = 1; p < n; ++p)
    {
        vector<int> lmin(p), lmax(p);
        lmin[0] = lmax[0] = a[p - 1];
        for (int j = 1; j < p; ++j)
        {
            lmin[j] = min(lmin[j - 1], a[p - 1 - j]);
            lmax[j] = max(lmax[j - 1], a[p - 1 - j]);
        }
 
        vector<int> rmin(n - p), rmax(n - p);
        rmin[0] = rmax[0] = a[p];
        for (int k = 1; k < n - p; ++k)
        {
            rmin[k] = min(rmin[k - 1], a[p + k]);
            rmax[k] = max(rmax[k - 1], a[p + k]);
        }
 
        int rk = 0;
        for (int j = p - 1; j >= 0; --j)
        {
            while (rk < n - p)
            {
                if (minm(lmin[j], lmax[j], rmin[rk], rmax[rk]))
                {
                    ans = min(ans, j + rk);
                    break;
                }
                rk++;
            }
        }
    }
 
    cout << (ans == n ? -1 : ans) << endl;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while (t--)
        solve();
 
    return 0;
}