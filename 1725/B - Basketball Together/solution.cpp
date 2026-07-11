#include <bits/stdc++.h>
using namespace std;
 
void solve(vector<int> &arr, int D)
{
    sort(arr.begin(), arr.end());
    int n = arr.size();
    if (n == 2)
    {
        if (arr[0] > D)
        {
            cout << 2 << endl;
            return;
        }
        else if (arr[1] > D || 2 * arr[1] > D)
        {
            cout << 1 << endl;
            return;
        }
    }
    int i = 0, j = n - 1;
    int cnt = 0;
    while (i <= j)
    {
        int q = D / arr[j];
        i += q;
        if (i <= j)
        {
            cnt++;
            j--;
        }
    }
    cout << cnt << endl;
    return;
}
 
int main()
{
    int n, d;
    cin >> n >> d;
    vector<int> arr(n);
    for (auto &it : arr)
    {
        cin >> it;
    }
    solve(arr, d);
    return 0;
}