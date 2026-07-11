#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void f(vector<int> &a, vector<int> &b);
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> x(n), y(n);
        for (int &v : x)
            cin >> v;
        for (int &v : y)
            cin >> v;
        f(x, y);
    }
    return 0;
}
 
void f(vector<int> &a, vector<int> &b)
{
    int n = a.size();
    if (b[0] != a[n - 1])
    {
        cout << "NO
";
        return;
    }
 
    for (int i = 1; i < n; ++i)
        if (a[i - 1] % a[i])
        {
            cout << "NO
";
            return;
        }
 
    for (int i = 0; i + 1 < n; ++i)
        if (b[i + 1] % b[i])
        {
            cout << "NO
";
            return;
        }
 
    for (int i = 0; i < n; ++i)
        if (__gcd(a[i], b[i]) != a[n - 1])
        {
            cout << "NO
";
            return;
        }
 
    for (int i = 0; i + 1 < n; ++i)
        if (__gcd(a[i], b[i + 1]) != a[n - 1])
        {
            cout << "NO
";
            return;
        }
 
    cout << "YES
";
}