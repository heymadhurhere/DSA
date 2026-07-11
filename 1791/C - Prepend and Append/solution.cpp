    #include <bits/stdc++.h>
    using namespace std;
 
    int solve(string s) {
        int n = s.length();
        int i = 0, j = n - 1;
        while (i < j) {
            if ((s[i] == '0' && s[j] == '1') || (s[i] == '1' && s[j] == '0')) {
                i++;
                j--;
            }
            else {
                break;
            }
        }
        return (j - i + 1);
    }
 
 
    int main () {
        int t;
        cin >> t;
        while (t--) {
           int n;
           cin >> n;
           string s;
           cin >> s;
           cout << solve(s) << endl;
        }
        return 0;
    }