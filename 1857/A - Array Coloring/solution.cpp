#include <bits/stdc++.h>
using namespace std;
 
string solve(vector<int> &arr)
{
    int n = arr.size();
    int odd = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 1)
            odd++;
    }
 
    if (odd % 2 == 1) return "NO";
    else return "YES";
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