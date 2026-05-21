class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        int n = queries.size();
        int m = pattern.length();

        for (int i = 0; i < n; i++) {
            // 2 pointers
            int l = 0, len = queries[i].length(), r = 0;
            bool flag = false;
            while (l < len and r < m) {
                if (queries[i][l] == pattern[r] && r == m - 1) {
                    flag = true;
                    l++;
                    r++;
                    break;
                } else if (queries[i][l] == pattern[r]) {
                    l++;
                    r++;
                } else {
                    if (queries[i][l] >= 'A' and queries[i][l] <= 'Z') {
                        flag = false;
                        break;
                    }
                    l++;
                }
            }
            if (flag and l < len) {
                while (l < len) {
                    if (queries[i][l] >= 'A' and queries[i][l] <= 'Z') {
                        flag = false;
                    }
                    l++;
                }
            }
            ans.push_back(flag);
        }
        return ans;
    }
};