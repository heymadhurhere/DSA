#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<long long, long long>
#define vi vector<long long>
#define vpii vector<pii>
#define all(x) x.begin(), x.end()
#define sz(x) (ll)(x).size()
#define F first
#define S second
const ll MOD = 1e9 + 7;
 
ll maxConsecutiveOnes(const string &s) {
    ll maxCount = 0, count = 0;
    for (char c : s) {
        if (c == '1') {
            count++;
            maxCount = max(maxCount, count);
        } else {
            count = 0;
        }
    }
    return maxCount;
}
 
ll leadingOnes(const string &s) {
    ll count = 0;
    for (char c : s) {
        if (c == '1')
            count++;
        else
            break;
    }
    return count;
}
 
ll trailingOnes(const string &s) {
    ll count = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '1')
            count++;
        else
            break;
    }
    return count;
}
 
 
 
ll solve(string& s) {
    if (s == "1") return 1;
    ll cnt = maxConsecutiveOnes(s);
    bool ok = false;
    for (char ch : s) {
        if (ch == '0') {
            ok = true;
            break;
        }
    }
    if (!ok) {
        return cnt * cnt;
    }
    ll cnt1 = leadingOnes(s);
    ll cnt2 = trailingOnes(s);
    cnt = max(cnt, cnt1 + cnt2);
    return (cnt - cnt / 2) * (cnt / 2 + 1);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << solve(s) << "
";
    }
    return 0;
}