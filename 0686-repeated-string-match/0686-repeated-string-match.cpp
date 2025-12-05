class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string tmp = "";
        int cnt = 0;

        if (b.length() == 0)
            return 1;
        // if (b.length() < a.length())
        //     return -1;

        while (tmp.length() < b.length()) {
            tmp += a;
            cnt++;
        }

        if (tmp.find(b) != std::string::npos)
            return cnt;

        tmp += a;
        cnt++;

        if (tmp.find(b) != std::string::npos)
            return cnt;

        return -1;
    }
};