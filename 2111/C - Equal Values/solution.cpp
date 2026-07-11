#include <bits/stdc++.h>
using namespace std;
 
long long solve(vector<int>& a) {
    int n = a.size();
    long long res = LLONG_MAX;
    for (int i = 0; i < n;) {
        int j = i;
        
        while (j + 1 < n && a[j + 1] == a[i]){
            j++;
        }
        long long val = a[i];
        long long rOpns = i;
        long long lOpns = n - j - 1;
        long long cost = val * (lOpns + rOpns);
 
        res = min(res, cost);
        i = j + 1;
    }
 
    return res;
}
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        vector<int> arr(x);
        for (int i = 0; i < x; i++) {
            cin >> arr[i];
        }
        cout << solve(arr) << endl;
    }
    return 0;
}