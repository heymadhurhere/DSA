class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string, int> mpp;

        int m = arr1.size(), n = arr2.size();
        for (int i = 0; i < m; i++) {
            string s = to_string(arr1[i]);
            int len = s.length();
            for (int j = 1; j <= len; j++) {
                string sub = s.substr(0, j);
                mpp[sub]++;
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            string s = to_string(arr2[i]);
            int len = s.length();
            for (int j = 1; j <= len; j++) {
                string sub = s.substr(0, j);
                if (mpp.find(sub) != mpp.end()) {
                    ans = max(ans, j);
                }
            }
        }
        return ans;
    }
};