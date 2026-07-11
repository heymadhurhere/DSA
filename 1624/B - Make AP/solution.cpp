#include <bits/stdc++.h>
using namespace std;
 
bool solve(long long a, long long b, long long c)
{
    return ((2 * b - c) % a == 0 && (2 * b - c) / a > 0) || ((a + c) % (2 * b) == 0 && (a + c) / (2 * b) > 0) || ((2 * b - a) % c == 0 && (2 * b - a) / c > 0);
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        cout << (solve(a, b, c) ? "YES" : "NO") << endl;
    }
    return 0;
}