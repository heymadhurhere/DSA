#include <bits/stdc++.h>
using namespace std;
 
bool fair(long long n) {
    long long num = n;
    while (num > 0) {
        int rem = num % 10;
        if (rem != 0 && n % rem != 0) {
            return false;
        }
        num /= 10;
    }
    return true;
}
 
void solve(vector<int>& arr)
{
    sort(begin(arr), end(arr));
    reverse(begin(arr), end(arr));
    for (int& it : arr) {
        cout << it <<" ";
    }
    cout << endl;
    return;
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
        for (int& it : arr) {
            cin >> it;
        }
        solve(arr);
    }
    return 0;
}