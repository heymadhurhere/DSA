#include <bits/stdc++.h>
using namespace std;
 
int solve(vector<int>& arr, int end) {
    int diff = 0;
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        diff = max(diff, arr[i + 1] - arr[i]);
    }
    int last = end - arr[n - 1];
    int begin = arr[0];
    return max({begin, 2 * last, diff});
}
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << solve(arr, x) << endl;
    }
}