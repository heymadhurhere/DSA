#include <bits/stdc++.h>
using namespace std;
 
long long solve(vector<long long>& arr) {
    int n = arr.size();
    long long ans = 0;
    int i = 0;
    while (i < n) {
        while (i < n && arr[i] == 0) i++;
        if (i < n && arr[i] != 0) {
            ans++;
            while (i < n && arr[i] != 0) i++;
        }
    }
    return min(ans, (long long)2);
}
 
int main() {
    long long t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> arr(n);
        for (long long i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << solve(arr) << endl;
    }
    return 0;
}