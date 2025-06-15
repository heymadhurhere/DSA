class Solution {
public:
    string generateTag(string caption) {
        stack<char> st;
        st.push('#');
        int i = 0, n = caption.length();
        bool flag = false;
        while (i < n) {
            if (!isalpha(caption[i]) && caption[i] != ' ') {
                i++;
                continue;
            }
            if (caption[i] == ' ') {
                flag = true;
            }
            else if (!flag) {
                st.push(tolower(caption[i]));
            }
            else {
                st.push(toupper(caption[i]));
                flag = false;
            }
            i++;
        }
        string s = "";
        while (!st.empty()) {
            s += st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());
        if (s.length() > 100) s = s.substr(0, 100);
        s[1] = tolower(s[1]);
        return s;
    }
};