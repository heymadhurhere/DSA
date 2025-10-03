class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.length();
        int i = 0;
        while (i < n) {
            if (st.empty()) {
                st.push(s[i]);
                i++;
            } else {
                if (s[i] == ')' && st.top() == '(') {
                    st.pop();
                    i++;
                } else if (s[i] == ']' && st.top() == '[') {
                    st.pop();
                    i++;
                } else if (s[i] == '}' && st.top() == '{') {
                    st.pop();
                    i++;
                } else {
                    st.push(s[i]);
                    i++;
                }
            }
        }
        return (st.size() == 0);
    }
};