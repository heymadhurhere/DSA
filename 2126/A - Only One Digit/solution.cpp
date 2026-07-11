#include <bits/stdc++.h>
using namespace std;
 
void f(int a);
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int a;
        cin >> a;
        f(a);
    }
    return 0;
}
 
void f(int a)
 
{
    int ans = INT_MAX;
 
    while (a > 0)
    {
        int rem = a % 10;
        a /= 10;
        
            ans = min(ans, rem);
        
    }
    cout << ans << endl;
    return;
}