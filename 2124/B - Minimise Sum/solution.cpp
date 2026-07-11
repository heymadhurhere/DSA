#include <bits/stdc++.h>
using namespace std;
 
void solve(vector<long long> &arr);
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
 
    cin >> t;
 
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> arr(n + 2);
        for (int i = 1; i <= n; i++)
            cin >> arr[i];
        solve(arr);
    }
 
    return 0;
}
 
void solve(vector<long long> &arr)
{
    int n = arr.size() - 2;
 
    vector<long long> prefMin(n + 2), suff(n + 3), diff(n + 2);
 
 
    prefMin[1] = arr[1];
 
    for (int i = 2; i <= n; i++)
        prefMin[i] = min(prefMin[i - 1], arr[i]);
 
    long long total = 0;
 
    for (int i = 1; i <= n; i++)
        total += prefMin[i];
 
    suff[n + 1] = 0;
 
    for (int i = n; i >= 1; i--)
        suff[i] = prefMin[i] + suff[i + 1];
 
    int flat = n + 1;
 
    for (int i = 2; i <= n - 1; i++)
    {
        if (prefMin[i] == prefMin[i - 1])
        {
            flat = i;
            break;
        }
    }
 
    for (int i = 2; i <= n; i++)
        diff[i] = prefMin[i - 1] - prefMin[i];
 
 
    long long best = 0, mini = LLONG_MAX;
 
    for (int j = 2; j <= n; j++)
    {
        long long save;
        if (j <= flat)
        {
            if (j == 2)
            {
                save = suff[j] - arr[j];
            }
            else
            {
                mini = min(mini, diff[j - 1]);
 
                save = suff[j] - min(arr[j], mini);
            }
        }
        else
        {
            save = suff[j];
        }
        best = max(best, save);
    }
 
    cout << total - best << endl;
    
    return;
}