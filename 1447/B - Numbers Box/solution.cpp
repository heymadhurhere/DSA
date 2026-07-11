#include <bits/stdc++.h>
using namespace std;
 
void solve(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();
    int sum = 0;
    int cnt = 0;
    int mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            sum += abs(arr[i][j]);
            if (arr[i][j] < 0)
            {
                cnt++;
            }
            mini = min(mini, abs(arr[i][j]));
        }
    }
    if (cnt % 2 != 0)
    {
        sum -= 2 * mini;
    }
    cout << sum << endl;
    return;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }
        solve(arr);
    }
    return 0;
}