#include <bits/stdc++.h>
using namespace std;
int solve(vector<int>& arr) {
    int n = arr.size();
    int cnt = 0;
    int i = 0;
    int last = -1e9;
    while (i < n) {
        if (arr[i] >= last + 2) {
            cnt++;
            last = arr[i];
        }
        i++;
    }
    return cnt;
}
int main() {
   
    int t;
    cin >> t;
 
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
 
        cout << solve(arr) << '
';
    }
 
    return 0;
}