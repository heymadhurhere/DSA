#include <bits/stdc++.h>
using namespace std;
 
string solve(int a, int x, int y)
{
    bool dist = false;
    for (int pnt = 1; pnt <= 100; pnt++)
    {
        if (pnt == a)
            continue;
        if (abs(pnt - x) < abs(a - x) && abs(pnt - y) < abs(a - y))
        {
            dist = true;
            break;
        }
    }
    if (dist)
        return "YES";
    else
        return "NO";
}
 
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, x, y;
        cin >> a >> x >> y;
        cout << solve(a, x, y) << endl;
    }
    return 0;
}