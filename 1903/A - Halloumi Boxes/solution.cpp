# include <bits/stdc++.h>
using namespace std;
 
string solve(vector<int>& arr, int k) {
    vector<int> temp = arr;
    sort(temp.begin(), temp.end());
    if (temp == arr) {
        return "YES";
    }
   if (k == 1 && temp != arr) {
    return "NO";
   }
    return "YES";
}
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n;
        cin >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << solve(arr, k) << endl;
    }
    return 0;
}