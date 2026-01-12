class Solution {
public:
    long long check(string s, unordered_map<string, int>& mpp) {
        int n = s.length();
        long long cnt = 0;
        for (int i = 0; i < 26; i++) {
            string tmp = s;
            for (int j = 0; j < tmp.length(); j++) {
                tmp[j] = ('a' + (tmp[j] - 'a' + i) % 26);
            }
            cnt += mpp[tmp];
        }
        return cnt;
    }
    long long countPairs(vector<string>& words) {
        int n = words.size();
        int m = words[0].length();
        unordered_map<string, int> mpp;
        long long cnt = 0;
        for (int i = n - 1; i >= 0; i--) {
            string pres = words[i];
            cnt += check(pres, mpp);
            mpp[pres]++;
        }
        return cnt;
    }
};