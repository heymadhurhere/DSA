    #include <bits/stdc++.h>
    using namespace std;
 
    bool diffparity(int a, int b) {
        return (a % 2 != b % 2);
    }
    int solve(vector<int>& arr) {
        int n = arr.size();
        int cnt = 0;
        for (int i = 0; i < n - 1; i++) {
            if ((arr[i] % 2) == (arr[i + 1] % 2)) {
                cnt++;
            }
        }
        return cnt;
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