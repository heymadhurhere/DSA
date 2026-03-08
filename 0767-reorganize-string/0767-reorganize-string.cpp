class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        vector<int> freq(26);
        for (int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
        }

        vector<pair<int, char>> tmp;

        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0)
                tmp.push_back({freq[i], char(i + 'a')});
        }

        sort(tmp.rbegin(), tmp.rend());
        string ans(n, ' ');

        int i = 0;
        for (auto& it : tmp) {
            // for (int j = 0; j < n; j++) {
            //     if (ans[j] == ' ') {
            //         i = j;
            //         break;
            //     }
            // }
            while (it.first--) {
                // only maximum freq character is the problem
                if (i >= n)
                    i = 1;
                ans[i] = it.second;
                i += 2;
            }
        }

        for (int i = 1; i < n; i++) {
            if (ans[i] == ans[i - 1])
                return "";
        }
        return ans;
    }
};