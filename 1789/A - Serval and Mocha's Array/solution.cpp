    #include <bits/stdc++.h>
    using namespace std;
 
    string solve(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        bool found = false;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (__gcd(arr[i], arr[j]) == 1 || __gcd(arr[i], arr[j]) == 2){
                    return "Yes";
                }
            }
        }
        return "No";
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