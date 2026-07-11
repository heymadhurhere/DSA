    #include <bits/stdc++.h>
    using namespace std;
 
    int solve(vector<int>& arr) {
    int n = arr.size();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 2) cnt++;
    }
    if (cnt % 2 == 1) return -1;
    if (cnt == 0) return 1;
    int cntAg = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 2) {
            cntAg++;
            cnt--;
            if (cntAg == cnt) return i + 1;
        }
    }
}
 
 
    int main () {
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