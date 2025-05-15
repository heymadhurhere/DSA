class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words,
                                         vector<int>& groups) {
        vector<string> ans;
        int n = words.size();
        int flag = -1;
        for (int i = 0; i < n; i++) {
            if (flag == -1 || groups[i] != flag) {
                ans.push_back(words[i]);
                flag = groups[i];
            }
        }
        return ans;
    }
};