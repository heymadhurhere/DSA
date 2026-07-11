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
 
ll f(ll n)
{
    int p[4] = {2, 3, 5, 7};
    ll res = n;
    for (int m = 1; m < 16; m++)
    {
        ll prod = 1;
        int b = 0;
        for (int i = 0; i < 4; i++)
        {
            int d = 1;
            for (int j = 0; j < i; j++)
                d *= 2;
            if ((m / d) % 2 == 1)
            {
                prod *= p[i];
                ++b;
            }
        }
        ll cnt = n / prod;
        if (b % 2 == 1)
            res -= cnt;
        else
            res += cnt;
    }
    return res;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while (t--)
    {
        ll l, r;
        cin >> l >> r;
        cout << f(r) - f(l - 1) << endl;
    }
    return 0;
}