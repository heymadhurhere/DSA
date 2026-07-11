#include <bits/stdc++.h>
using namespace std;
 
int solve(vector<int> &arr)
{
    int n = arr.size();
    vector<int> temp = arr;
    sort(temp.begin(), temp.end());
    if (temp != arr) return 0;
    if (arr[0] == arr[n - 1]) return 1;
    int diff = INT_MAX;
    for (int i = 0; i < n - 1; i++) {
        diff = min(diff, arr[i + 1] - arr[i]);
    }
    return (diff / 2) + 1;
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
       cout << solve(arr) << endl;
    }
    return 0;
}