class Solution {
public:
        bool isnum(char ch) {
            return (ch >= '0' && ch <= '9');
        }
        int myAtoi(string s) {
            int n = s.length();
            int i = 0;
            bool pos = true, parity = false;
            
            string tmp = "";

            // manage space
            while (i < n && s[i] == ' ') i++;

            // manage parity
            if (s[i] == '-') {
                pos = false;
                parity = true;
                i++;
            } else if (s[i] == '+') {
                parity = true;
                i++;
            } else if (!isnum(s[i])) {
                return 0;
            }

            // manage zeroes
            while (i < n && s[i] == '0') {
                i++;
            }

            // manage numbers
            while (i < n && isnum(s[i])) {
                tmp += s[i];
                i++;
            }

            if (tmp.empty()) return 0;

            vector<int> store;
            for (int i = 0; i < tmp.length(); i++) {
                store.push_back(tmp[i] - '0');
            }
            long long ans = 0;

            for (int i = 0; i < store.size(); i++) {
                if (ans * 10 + store[i] <= INT_MAX) {
                    ans = ans * 10 + store[i];
                } else {
                    if (!pos) return INT_MIN;
                    else return INT_MAX;
                }
            }

            if (!pos) ans *= (-1);
            return (int)ans;
        }
};