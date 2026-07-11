#include <bits/stdc++.h>
using namespace std;
 
void solve(long long n)
{
    long long a = 1;
    long long b = n - 1;
    for (long long i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            a = n / i;
            b = n - a;
            break;
        }
    }
    cout << a << " " << b << endl;
    return;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        solve(n);
    }
    return 0;
}