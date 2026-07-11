#include <bits/stdc++.h>
using namespace std;
 
string solve(int n, int k, const string &s)
{
    
    int c0 = 0, c1 = 0;
    for (auto it : s) {
        if (it == '0') c0++;
        else c1++;
    }
 
    int m = n / 2;
    int x = m - k;
 
    if ((0 <= x && x <= m) && c0 >= x && c1 >= x && ((c0 - x) % 2 == 0) && ((c1 - x) % 2 == 0))
    {
        return "YES";
    }
 
    return "NO";
}
 
int main()
{
 
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        string s;
        cin >> n >> k >> s;
        cout << solve(n, k, s) << '
';
    }
 
    return 0;
}