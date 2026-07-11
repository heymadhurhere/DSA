#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<long long, long long>
#define vi vector<long long>
#define vpii vector<pii>
#define all(s) s.begin(), s.end()
#define sz(s) (ll)(s).size()
#define F first
#define S second
const ll MOD = 1e9 + 7;
 
 
void solve(vi& a, vector<vector<int>>& query) {
    ll n = sz(a);
    ll sum = accumulate(all(a), 0LL);
    set<ll> st;
 
    ll last = -1;
 
    for (auto& q : query) {
        if (q[0] == 1) {
            if (st.count(q[1])) {
                sum = sum - a[q[1]] + q[2];
                cout << sum << "
";
                a[q[1]] = q[2];
            } else {
                st.insert(q[1]);
                sum = sum + q[2] - (last == -1 ? a[q[1]] : last);
                cout << sum << "
";
                a[q[1]] = q[2];
            }
        }
        if (q[0] == 2) {
            st.clear();
            sum = 1LL * n * q[1];
            cout << sum << "
";
            last = q[1];
        }
    }
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll n, q;
    cin >> n >> q;
    vi a(n);
 
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    vector<vector<int>> query;
 
    while (q--) {
        ll type;
        cin >> type;
        if (type == 1) {
            ll index, value;
            cin >> index >> value;
            index--;
            query.push_back({1, (int)index, (int)value});
        } else {
            ll value;
 
            cin >> value;
 
            query.push_back({2, (int)value, 0});
        }
    }
 
    solve(a, query);
 
    return 0;
}