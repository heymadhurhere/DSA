class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (s.length() < k)
            return false;
        set<string> st;
        string tmp = "";
        for (int i = 0; i < k; i++) {
            tmp += s[i];
        }
        st.insert(tmp);
        for (int i = k; i < s.length(); i++) {
            tmp.erase(0, 1);
            tmp.push_back(s[i]);
            st.insert(tmp);
        }
        return st.size() == (1 << k);
    }
};