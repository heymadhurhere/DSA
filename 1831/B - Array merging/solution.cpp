#include <bits/stdc++.h>
using namespace std;
 
long long natSum(long long n) {
    return (n * (n + 1)) / 2;
}
 
void solve(vector<int>& a, vector<int>& b) {
    int n = a.size();
    unordered_map<int, int> mppa;
    unordered_map<int, int> mppb;
    int i = 0;
    while (i < n) {
        int cnt = 1;
        while (i + 1 < n && a[i] == a[i + 1]) {
            cnt++;
            i++;
        }
        mppa[a[i]] = max(mppa[a[i]], cnt);
        i++;
    }
    int j = 0;
    while (j < n) {
        int cnt = 1;
        while (j + 1 < n && b[j] == b[j + 1]) {
            cnt++;
            j++;
        }
        mppb[b[j]] = max(mppb[b[j]], cnt);
        j++;
    }
    int ans = 0;
    for (auto& it : a) {
        ans = max(ans, mppa[it] + mppb[it]);
    }
    for (auto& it : b) {
        ans = max(ans, mppa[it] + mppb[it]);
    }
    cout << ans << endl;
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
        vector<int> a(n), b(n);
        for (auto & it : a) {
            cin >> it;
        }
        for (auto & it : b) {
            cin >> it;
        }
        solve(a, b);
    }
    return 0;
}