#include <bits/stdc++.h>
using namespace std;
 
void s(long long x1, long long y1, long long x2, long long y2, vector<int> &a)
{
    long long d = accumulate(a.begin(), a.end(), 0);
    long long dx = x1 - x2, dy = y1 - y2;
    long long sq = dx * dx + dy * dy;
    long long mx = *max_element(a.begin(), a.end());
    long long maxr = d * d;
    long long minr = max(0LL, 2 * mx - d);
    long long minr_sq = minr * minr;
 
    if (sq >= minr_sq && sq <= maxr)
        cout << "Yes
";
    else
        cout << "No
";
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
        vector<int> v(n);
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (auto &el : v)
            cin >> el;
        s(x1, y1, x2, y2, v);
    }
    return 0;
}