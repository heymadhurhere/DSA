#include <bits/stdc++.h>
using namespace std;
 
void solve(vector<int> &arr, int n, int k)
{
    long long sum = 0;
    int step = n / 2 + 1;
    int idx = arr.size() - step;
 
    while (k--)
    {
        sum += arr[idx];
        idx -= step;
    }
    cout << sum << "
";
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
        vector<int> arr(n * k);
        for (int i = 0; i < n * k; i++)
        {
            cin >> arr[i];
        }
        solve(arr, n, k);
    }
    return 0;
}