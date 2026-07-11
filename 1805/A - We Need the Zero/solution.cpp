    #include <bits/stdc++.h>
    using namespace std;
 
    int solve(vector<int>& arr) {
        int n = arr.size();
        int ans = arr[0];
        for (int i = 1; i < n; i++) {
            ans ^= arr[i];
        }
        if (n % 2 == 0 && ans == 0) return 1;
        else if (n % 2 == 0 && ans != 0) return -1;
        return ans;
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