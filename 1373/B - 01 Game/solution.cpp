#include <bits/stdc++.h>
using namespace std;
 
void solve(string s)
{
    int zero = 0, one = 0;
    for (auto &it : s)
    {
        if (it == '0')
            zero++;
        else
            one++;
    }
    int num = min(zero, one);
    if (num % 2 == 0)
    {
        cout << "NET" << endl;
        return;
    }
    cout << "DA" << endl;
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
        string s;
        cin >> s;
        solve(s);
    }
    return 0;
}