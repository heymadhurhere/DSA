#include <bits/stdc++.h>
using namespace std;
 
string solve(vector<int> &arr, int x)
{
    int n = arr.size();
    int first = -1, last = -1;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] == 1)
        {
            if (first == -1)
                first = i;
            last = i;
        }
    }
    int time = last - first + 1;
    return (time <= x) ? "YES" : "NO";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << solve(arr, x) << endl;
    }
    return 0;
}