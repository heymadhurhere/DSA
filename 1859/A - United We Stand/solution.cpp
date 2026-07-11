#include <bits/stdc++.h>
using namespace std;
 
void solve(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    int n = arr.size();
    if (arr[0] == arr[n - 1])
    {
        cout << -1 << endl;
        return;
    }
    vector<int> b, c;
    b.push_back(arr[0]);
    int idx = -1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[0])
        {
            b.push_back(arr[i]);
        }
        else
        {
            idx = i;
            break;
        }
    }
    for (int i = idx; i < n; i++)
    {
        c.push_back(arr[i]);
    }
    for (int bi : b)
    {
        for (int cj : c)
        {
            if (bi % cj == 0)
            {
                cout << -1 << endl;
                return;
            }
        }
    }
    cout << b.size() << " " << c.size() << endl;
    for (auto &it : b)
    {
        cout << it << " ";
    }
    cout << endl;
    for (auto &it : c)
    {
        cout << it << " ";
    }
    cout << endl;
    return;
}
 
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        solve(a);
        cout << endl;
        ;
    }
    return 0;
}