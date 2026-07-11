#include <bits/stdc++.h>
using namespace std;
 
string solve(vector<int> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    if (arr[0] == arr[n - 1]) return "Yes";
    int cnt1 = 0, cnt2 = 0;
    for (auto it : arr) {
        if (it == arr[0]) cnt1++;
        else if (it == arr[n - 1]) cnt2++;
        else return "No";
    }
    if (n % 2 == 0) {
        if (cnt1 != cnt2) return "No";
    }
    else {
        if (abs(cnt1 - cnt2) != 1) return "No";
    }
    return "Yes";
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << solve(arr) << endl;
    }
    return 0;
}