class Solution {
public:
    std::string toLower(std::string s) {
        std::transform(s.begin(), s.end(), s.begin(),
                       [](unsigned char c) { return std::tolower(c); });
        return s;
    }

    string capitalizeTitle(string title) {
        queue<string> q;
        int j = 0, n = title.length();
        string tmp = "";
        while (j < n) {
            if (title[j] == ' ') {
                q.push(tmp);
                tmp = "";
                j++;
            } else {
                tmp += tolower(title[j]);
                j++;
            }
        }
        q.push(tmp);
        string ans;
        while (!q.empty()) {
            string x = q.front();
            q.pop();
            if (x.length() > 2) {
                char ch = x[0];
                x[0] = toupper(ch);
            }
            ans += x;
            ans += ' ';
        }
        ans.pop_back();
        return ans;
    }
};