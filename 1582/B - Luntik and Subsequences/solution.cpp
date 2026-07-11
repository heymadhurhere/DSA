#include <bits/stdc++.h>
using namespace std;
 
long long solve(vector<int>& arr) {
    long long n = arr.size();
    long long one = 0, zero = 0;
    for (auto & it : arr) {
        if (it == 1) one++;
        else if (it == 0) zero++;
    }
    if (one == 0) return 0;
    if (zero == 0) return one;
    return (pow(2, zero) * one);
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