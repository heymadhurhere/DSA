#include <bits/stdc++.h>
using namespace std;
 
long long solve(long long x, long long n)
{
    if (x % 2 != 0)
    {
        long long rem = n % 4;
        if (rem == 0)
            return x;
        else if (rem == 1)
            return x + n;
        else if (rem == 2)
            return x - 1;
        else
            return x - n - 1;
    }
    else
    {
        long long rem = n % 4;
        if (rem == 0)
            return x;
        else if (rem == 1)
            return x - n;
        else if (rem == 2)
            return x + 1;
        else
            return x + n + 1;
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        long long x, n;
        cin >> x >> n;
        cout << solve(x, n) << endl;
    }
    return 0;
}