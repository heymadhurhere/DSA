class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length(), ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            map<char, int> mpp;
            for (int j = i; j < n; j++) {
                mpp[s[j]]++;
                int num = mpp[s[i]];
                bool flag = true;
                for (auto& it : mpp) {
                    if (it.second != num) {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                    ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};