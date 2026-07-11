#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve(int n, int k, vector<int>& a, vector<int>& b)
{
    int cnt = 0;
    ll sum = 0, ans = 0;
    int maxb = INT_MIN;
    for (int i = 0; i < n && cnt < k; i++) {
        sum += a[i];
        maxb = max(maxb, b[i]);
        cnt++;
        ans = max(ans, sum + (k - cnt) * maxb);
    }
    // ans += (k - cnt) * maxb; n quest completed, why go further, Monocarp is busy :))
    cout << ans << endl;
    return;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int &it : a) {
        cin >> it;
    }
    for (int &it : b) {
        cin >> it;
    }
    solve(n, k, a, b);
    }
    return 0;
}