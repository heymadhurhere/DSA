#include <bits/stdc++.h>
using namespace std;
 
void solve(vector<long long> &arr)
{
    int n = arr.size();
    if(arr[0]==1)arr[0]++;
    for (long long i = 1; i < n; i++)
    {
        if (arr[i]==1)arr[i]++;
        if(arr[i]%arr[i-1]==0) arr[i]++;
    }
    for (long long i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
 
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> arr(n);
        for (long long i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        solve(arr);
    }
    return 0;
}