class Solution {
public:
    int compareVersion(string version1, string version2) {
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < version1.length(); i++) {
            if (version1[i] == '.')
                cnt1++;
        }
        for (int i = 0; i < version2.length(); i++) {
            if (version2[i] == '.')
                cnt2++;
        }
        cnt1++;
        cnt2++;
        int sz = max(cnt1, cnt2);
        vector<int> tmp1, tmp2;
        int i = 0, n = version1.length();
        string x = "";
        while (i < n) {
            if (version1[i] == '.') {
                int y = stoi(x);
                tmp1.push_back(y);
                i++;
                x = "";
            } else {
                x += version1[i];
                i++;
            }
        }
        int y = stoi(x);
        tmp1.push_back(y);
        x = "";
        i = 0, n = version2.length();
        while (i < n) {
            if (version2[i] == '.') {
                int y = stoi(x);
                tmp2.push_back(y);
                i++;
                x = "";
            } else {
                x += version2[i];
                i++;
            }
        }
        y = stoi(x);
        tmp2.push_back(y);
        x = "";
        int ans = 0;
        // case1 => both sizes equal
        if (cnt1 == cnt2) {
            for (int i = 0; i < cnt1; i++) {
                if (tmp1[i] < tmp2[i])
                    return -1;
                if (tmp1[i] > tmp2[i])
                    return 1;
            }
            return 0;
        }
        // case2 => sz1 > sz2
        if (cnt1 > cnt2) {
            int diff = cnt1 - cnt2;
            for (int i = 0; i < diff; i++) {
                tmp2.push_back(0);
            }
            for (int i = 0; i < cnt1; i++) {
                if (tmp1[i] < tmp2[i])
                    return -1;
                if (tmp1[i] > tmp2[i])
                    return 1;
            }
            return 0;
        }
        // case3 => sz1 < sz2
        if (cnt1 < cnt2) {
            int diff = cnt2 - cnt1;
            for (int i = 0; i < diff; i++) {
                tmp1.push_back(0);
            }
            for (int i = 0; i < cnt2; i++) {
                if (tmp1[i] < tmp2[i])
                    return -1;
                if (tmp1[i] > tmp2[i])
                    return 1;
            }
            return 0;
        }
        return 0;
    }
};