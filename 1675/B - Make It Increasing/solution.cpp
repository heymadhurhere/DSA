#include <bits/stdc++.h>
using namespace std;
 
void solve(vector<long long>& arr) {
    int n = arr.size();
    long long ans = 0;
    for (int i = n - 2; i >= 0; i--) {
        while (arr[i] >= arr[i + 1]) {
            ans++;
            arr[i] /= 2;
            if (arr[i] == 0) break;
        }
        if (arr[i] == 0 && arr[i + 1] == 0) {
            ans = -1;
            break;
        }
    }
    cout << ans << endl;
}
 
int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<long long> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        solve(arr);
    }
    return 0;
}