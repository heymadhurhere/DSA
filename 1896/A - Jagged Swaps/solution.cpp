#include <bits/stdc++.h>
using namespace std;
 
string solve(vector<int> &arr)
{
    int n = arr.size();
    bool flag = true;
    while (flag) {
        flag = false;;
        for (int i = 1; i < n - 1; i++) {
            if (arr[i] > arr[i + 1] && arr[i] > arr[i - 1]) {
                swap(arr[i], arr[i + 1]);
                flag = true;
            }
        }
    }
    vector<int> temp = arr;
    sort(temp.begin(), temp.end());
    return (temp == arr)  ? "YES" : "NO";
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