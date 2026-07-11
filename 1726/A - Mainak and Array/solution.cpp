#include <bits/stdc++.h>
using namespace std;
 
int solve(vector<int>& arr) {
    int n = arr.size();
    int maxDiff = INT_MIN;
    for (int i = 1; i < n; i++) {
        int diff = arr[i] - arr[0];
        maxDiff = max(maxDiff, diff);
    }
    for (int i = 0; i < n - 1; i++) {
        int diff = arr[n - 1] - arr[i];
        maxDiff = max(maxDiff, diff);
    }
    for (int i = 0; i < n - 1; i++) {
        int diff = arr[i] - arr[i + 1];
        maxDiff = max(maxDiff, diff);
    }
    int diff = arr[n - 1] - arr[0];
    maxDiff = max(maxDiff, diff);
    return maxDiff;
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
        cout << solve(arr) << endl;
    }
    return 0;
}