#include <bits/stdc++.h>
using namespace std;
 
const long long INF = 4e18;
 
void updMin(long long val, long long &mn, long long &secMn, int &cnt)
{
    if (val < mn)
    {
        secMn = mn;
        mn = val;
        cnt = 1;
    }
    else if (val == mn)
    {
        ++cnt;
    }
    else if (val < secMn)
    {
        secMn = val;
    }
}
 
void updMax(long long val, long long &mx, long long &secMx, int &cnt)
{
    if (val > mx)
    {
        secMx = mx;
        mx = val;
        cnt = 1;
    }
    else if (val == mx)
    {
        ++cnt;
    }
    else if (val > secMx)
    {
        secMx = val;
    }
}
 
long long fitArea(long long w, long long h, long long n)
{
    long long area = w * h;
    if (area >= n)
        return area;
 
    long long newW = max(w, (n + h - 1) / h);
    long long newH = max(h, (n + w - 1) / w);
 
    return min(newW * h, newH * w);
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
 
        if (n == 1)
        {
            cout << 1 << '
';
            long long x, y;
            cin >> x >> y;
            continue;
        }
 
        vector<pair<long long, long long>> pts(n);
        for (int i = 0; i < n; ++i)
            cin >> pts[i].first >> pts[i].second;
 
        long long mnX = INF, secMnX = INF, mxX = -INF, secMxX = -INF;
        long long mnY = INF, secMnY = INF, mxY = -INF, secMxY = -INF;
        int cntMnX = 0, cntMxX = 0, cntMnY = 0, cntMxY = 0;
 
        for (auto &p : pts)
        {
            long long x = p.first;
            long long y = p.second;
            updMin(x, mnX, secMnX, cntMnX);
            updMax(x, mxX, secMxX, cntMxX);
            updMin(y, mnY, secMnY, cntMnY);
            updMax(y, mxY, secMxY, cntMxY);
        }
 
        long long baseArea = (mxX - mnX + 1) * (mxY - mnY + 1);
        long long res = baseArea;
 
        for (auto &p : pts)
        {
            long long x = p.first;
            long long y = p.second;
            long long curMnX = (x == mnX && cntMnX == 1) ? secMnX : mnX;
            long long curMxX = (x == mxX && cntMxX == 1) ? secMxX : mxX;
            long long curMnY = (y == mnY && cntMnY == 1) ? secMnY : mnY;
            long long curMxY = (y == mxY && cntMxY == 1) ? secMxY : mxY;
 
            long long w = curMxX - curMnX + 1;
            long long h = curMxY - curMnY + 1;
 
            res = min(res, fitArea(w, h, n));
        }
 
        cout << res << '
';
    }
 
    return 0;
}