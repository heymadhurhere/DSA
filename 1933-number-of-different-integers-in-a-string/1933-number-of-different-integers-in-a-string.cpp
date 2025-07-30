class Solution {
public:
    int numDifferentIntegers(string word) {
        int n = word.length();
        for (int i = 0; i < n; i++) {
            if (isalpha(word[i]))
                word[i] = ' ';
        }

        string num = "";
        set<string> st;

        for (int i = 0; i < n; i++) {
            if (isdigit(word[i])) {
                num += word[i];
            }
            if (word[i] == ' ') {
                if (!num.empty()) {
                    num.erase(0, num.find_first_not_of('0'));
                    if (num.empty())
                        num = "0";
                    st.insert(num);
                    num = "";
                }
            }
        }

        if (!num.empty()) {
            num.erase(0, num.find_first_not_of('0'));
            if (num.empty())
                num = "0";
            st.insert(num);
        }

        return st.size();
    }
};