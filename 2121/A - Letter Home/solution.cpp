#include <bits/stdc++.h>
using namespace std;
 
long long solve(long long s, vector<long long>& arr) {
    long long n = arr.size();
    sort(arr.begin(), arr.end());
    long long begin = arr[0], end = arr[n - 1];
    if (s > end) {
        return s - begin;
    }
    else if (s < begin) {
        return end - s;
    }
    else {
        return min(s - begin, end - s) + end - begin;
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while (t--) {
        long long n, s;
        cin >> n >> s;
        vector<long long> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << solve(s, arr) << endl;
    }
    return 0;
}