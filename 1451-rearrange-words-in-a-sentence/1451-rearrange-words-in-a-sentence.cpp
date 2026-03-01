class Solution {
public:
    string arrangeWords(string text) {
        text[0] = tolower(text[0]);
        vector<pair<int, pair<int, string>>> tmp; // {length, {idx, string}}
        stringstream ss(text);
        string s;
        int i = 0;
        while (ss >> s) {
            tmp.push_back({s.length(), {i, s}});
            i++;
        }
        sort(tmp.begin(), tmp.end());
        string ans;
        for (auto& it : tmp) {
            ans += it.second.second;
            ans += " ";
        }
        ans.pop_back();
        ans[0] = toupper(ans[0]);
        return ans;
    }
};