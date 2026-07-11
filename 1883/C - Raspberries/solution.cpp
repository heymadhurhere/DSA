#include <bits/stdc++.h>
using namespace std;
 
void solve(vector<int> &arr, int k)
{
    int n = arr.size();
    int even = 0;
    int ans = INT_MAX;
    for (auto &it : arr)
    {
        if (it % 2 == 0)
            even++;
        if (it % k == 0)
            ans = 0;
        ans = min(ans, (k - it % k));
    }
    if (k == 4)
    {
        if (even >= 2)
            ans = min(ans, 0);
        else if (even == 1)
            ans = min(ans, 1);
        else if (even == 0)
            ans = min(ans, 2);
    }
    cout << ans << endl;
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
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        solve(arr, k);
    }
    return 0;
}