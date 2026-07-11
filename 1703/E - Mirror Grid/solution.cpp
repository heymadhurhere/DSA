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
// const ll MOD = 1e9 + 7;
 
ll solve(vector<vi> &mat)
{
    ll n = mat.size();
    ll cnt = 0;
    for (ll i = 0; i < n / 2; i++)
    {
 
        for (ll j = 0; j < n / 2; j++)
        {
            ll cnt0 = 0, cnt1 = 0;
            if (mat[i][j] == 0)
                cnt0++;
            else
                cnt1++;
            if (mat[j][n - 1 - i] == 0)
                cnt0++;
            else
                cnt1++;
            if (mat[n - 1 - i][n - 1 - j] == 0)
                cnt0++;
            else
                cnt1++;
            if (mat[n - 1 - j][i] == 0)
                cnt0++;
            else
                cnt1++;
 
            cnt += min(cnt0, cnt1);
        }
        // if (cnt0 == 0 || cnt1 == 0) continue;
    }
    if (n % 2 == 1)
    {
        ll idx = n / 2;
 
        for (ll i = 0; i < n / 2; i++)
        {
            ll cnt0 = 0, cnt1 = 0;
 
            if (mat[idx][i] == 0)
                cnt0++;
            else
                cnt1++;
            if (mat[i][idx] == 0)
                cnt0++;
            else
                cnt1++;
            if (mat[idx][n - 1 - i] == 0)
                cnt0++;
            else
                cnt1++;
            if (mat[n - 1 - i][idx] == 0)
                cnt0++;
            else
                cnt1++;
            cnt += min(cnt0, cnt1);
        }
        // if (mat[idx][idx] == 0) cnt0 -= 2;
        // else cnt1 -= 2;
    }
    return cnt;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<vector<ll>> mat(n, vector<ll>(n));
        for (ll i = 0; i < n; i++)
        {
            string row;
            cin >> row;
            for (ll j = 0; j < n; j++)
            {
                mat[i][j] = row[j] - '0';
            }
        }
        cout << solve(mat) << "
";
    }
 
    return 0;
}