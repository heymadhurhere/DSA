#include <bits/stdc++.h>
using namespace std;
 
void solve(long long w, long long h, vector<long long>& x0, vector<long long>& xn, vector<long long>& y0, vector<long long>& yn) {
    long long a1 = (x0.back() - x0[0]) * h;
    long long a2 = (xn.back() - xn[0]) * h;
    long long a3 = (y0.back() - y0[0]) * w;
    long long a4 = (yn.back() - yn[0]) * w;
    long long ans = max({a1, a2, a3, a4});
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
       long long w, h;
       cin >> w >> h;
       long long k1;
        cin >> k1;
        vector<long long> x0(k1);
        for (auto& it : x0) cin >> it;
 
        long long k2;
        cin >> k2;
        vector<long long> xn(k2);
        for (auto& it : xn) cin >> it;
 
        long long k3;
        cin >> k3;
        vector<long long> y0(k3);
        for (auto& it : y0) cin >> it;
 
        long long k4;
        cin >> k4;
        vector<long long> yn(k4);
        for (auto& it : yn) cin >> it;
        solve(w, h, x0, xn, y0, yn);
    }
    return 0;
}