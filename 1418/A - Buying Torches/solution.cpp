#include <bits/stdc++.h>
using namespace std;
 
void solve(long long x, long long y, long long k)
{
    long long stks = k * y + k - 1;
    long long gain = x - 1;
    long long ans = 0;
    ans += (stks + gain - 1) / gain;
    ans += k;
    cout << ans << endl;
    return;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        long long x, y, k;
        cin >> x >> y >> k;
        solve(x, y, k);
    }
    return 0;
}