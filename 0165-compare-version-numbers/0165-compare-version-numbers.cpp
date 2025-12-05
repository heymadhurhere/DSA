class Solution {
public:
    vector<int> parse(string s) {
        vector<int> ans;
        int n = s.length();
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && s[j] != '.') {
                j++;
            }
            string tmp = s.substr(i, j - i);
            ans.push_back(stoi(tmp));
            i = j + 1;
        }
        return ans;
    }
    int compareVersion(string version1, string version2) {
        vector<int> v1 = parse(version1);
        vector<int> v2 = parse(version2);

        int m = max(v1.size(), v2.size());
        v1.resize(m, 0);
        v2.resize(m, 0);

        for (int i = 0; i < m; i++) {
            if (v1[i] < v2[i])
                return -1;
            if (v1[i] > v2[i])
                return 1;
        }
        return 0;
    }
};