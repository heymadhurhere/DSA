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
 
string solve(string s) {
    ll n = s.length();
    string ans = "";
 
    vi hash(26, 0);
    for (ll i = 0; i < n; i++) {
        hash[s[i] - 'a']++;
    }
 
    for (ll i = 0; i < 26; i++) {
        if (hash[i] == 0) {
            ans += (char)(i + 'a');
            return ans;
        }
    }
 
    // make 2 sized substring
    string tmp = "";
    tmp += s[0];
    tmp += s[1];
 
    set<string> st;
    st.insert(tmp);
 
    for (ll i = 2; i < n; i++) {
        tmp.erase(tmp.begin());
        tmp += s[i];
        st.insert(tmp);
    }
 
    for (ll i = 0; i < 26; i++) {
        for (ll j = 0; j < 26; j++) {
            string curr = "";
            curr += (char)(i + 'a');
            curr += (char)(j + 'a');
            if (st.find(curr) == st.end()) {
                return curr;
            }
        }
    }
 
    st.clear();
    // make 3 sized substring
    tmp = "";
    tmp += s[0];
    tmp += s[1];
    tmp += s[2];
 
    st.insert(tmp);
 
    for (ll i = 3; i < n; i++) {
        tmp.erase(tmp.begin());
        tmp += s[i];
        st.insert(tmp);
    }
 
    for (ll i = 0; i < 26; i++) {
        for (ll j = 0; j < 26; j++) {
            for (ll k = 0; k < 26; k++) {
                string curr = "";
                curr += (char)(i + 'a');
                curr += (char)(j + 'a');
                curr += (char)(k + 'a');
                if (st.find(curr) == st.end()) {
                    return curr;
                }
            }
        }
    }
 
    st.clear();
    return ans;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        cout << solve(s) << endl;
    }
 
    return 0;
}