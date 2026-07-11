    #include <bits/stdc++.h>
    using namespace std;
 
    void solve(string s)
    {
        int n = s.size();
        int zero = 0, one = 0;
        for (auto &it : s) {
            if (it == '0') zero++;
            else one++;
        }
        int t = 0;
        for (auto& it : s) {
            if (it == '0' && one > 0) {
                one--;
                t++;
            }
            else if (it == '1' && zero > 0) {
                zero--;
                t++;
            }
            else break;
        }
        cout << n - t << endl;
    }
 
    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int t;
        cin >> t;
        while (t--)
        {
            string s;
            cin >> s;
            solve(s);
        }
        return 0;
    }