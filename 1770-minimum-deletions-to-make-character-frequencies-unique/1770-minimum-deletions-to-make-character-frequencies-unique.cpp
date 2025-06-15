class Solution {
public:
    int minDeletions(string s) {
        vector<int> hash(26, 0);
        for (char ch : s)
            hash[ch - 'a']++;
        unordered_set<int> st;
        int cnt = 0;
        for (int it : hash) {
            while (it > 0 && st.count(it)) {
                it--;
                cnt++;
            }
            if (it > 0) {
                st.insert(it);
            }
        }
        return cnt;
    }
};