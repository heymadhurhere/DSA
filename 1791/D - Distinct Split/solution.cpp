#include <bits/stdc++.h>
using namespace std;
 
long long natSum(long long n) {
    return (n * (n + 1)) / 2;
}
 
void solve(string& s) {
    int n = s.length();
    unordered_set<char> st1, st2;
    vector<int> temp1(n), temp2(n);
    for (int i = 0; i < n; i++) {
        st1.insert(s[i]);
        temp1[i] = st1.size();
    }
    for (int i = n - 1; i >= 0; i--) {
        st2.insert(s[i]);
        temp2[i] = st2.size();
    }
    int maxi = INT_MIN;
    for (int i = 0; i < n - 1; i++) {
        maxi = max(maxi, temp1[i] + temp2[i + 1]);
    }
    cout << maxi << endl;
    return;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        solve(s);
    }
    return 0;
}