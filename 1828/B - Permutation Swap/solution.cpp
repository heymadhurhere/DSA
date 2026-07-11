#include <bits/stdc++.h>
using namespace std;
 
void solve(vector<int>& arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        arr[i] = abs(arr[i] - (i + 1));
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = __gcd(ans, arr[i]);
    }
    cout << ans << endl;
}
 
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        solve(arr);
    }
    return 0;
}