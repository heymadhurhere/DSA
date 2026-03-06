class Solution {
public:
    bool isGood(string tmp) {
        int n = tmp.length();
        char ch = tmp[0];
        for (int i = 0; i < n; i++) {
            if (tmp[i] != ch)
                return false;
        }
        return true;
    }
    int cntOcc(string tmp, string s) {
        int cnt = 0;
        int i = 0;
        while ((i = s.find(tmp, i)) != string::npos) {
            cnt++;
            i++;
        }
        return cnt;
    }
    int maximumLength(string s) {
        int n = s.length();
        int maxi = -1;

        for (int i = 0; i < n; i++) {
            string tmp = "";
            for (int j = i; j < n; j++) {
                tmp += s[j];
                if (isGood(tmp)) {
                    if (cntOcc(tmp, s) >= 3) {
                        maxi = max(maxi, (int)tmp.length());
                    } else
                        break;
                } else
                    break;
            }
        }
        return maxi;
    }
};