#include <bits/stdc++.h>
using namespace std;
 
string solve(vector<int>& arr) {
    int n = arr.size();
    int sum = accumulate(arr.begin(), arr.end(), 0);
    if (sum > n - 1) {
        return "YES";
    }
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == 0 && arr[i + 1] == 0) {
            return "YES";
        }
    }
    return "NO";
}
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << solve(arr) << '
';
    }
    return 0;
}