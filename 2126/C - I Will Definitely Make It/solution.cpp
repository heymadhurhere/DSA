#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void f(vector<int>& a, int x);
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
 
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (auto &y : a)
            cin >> y;
        f(a, x);
    }
 
    return 0;
}
 
void f(vector<int> &a, int x)
{
    int n = a.size();
    int cur = a[x - 1];
    int mx = *max_element(a.begin(), a.end());
 
    if (cur == mx)
    {
        cout << "YES" << endl;
        return;
    }
 
    vector<int> b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
 
    int idx = lower_bound(b.begin(), b.end(), cur) - b.begin();
 
    for (int i = idx; i + 1 < (int)b.size(); i++)
    {
        if (b[i + 1] - b[i] > cur)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    return;
}