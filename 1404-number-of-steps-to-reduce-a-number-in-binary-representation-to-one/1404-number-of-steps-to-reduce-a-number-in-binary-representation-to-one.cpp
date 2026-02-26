class Solution {
public:
    void addOne(string& s) {
        int n = s.size();
        int carry = 1;

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '1' && carry == 1) {
                s[i] = '0';
            } else if (carry == 1) {
                s[i] = '1';
                carry = 0;
                break;
            }
        }

        if (carry == 1) {
            s = "1" + s;
        }
    }
    int numSteps(string s) {
        int cnt = 0;
        while (s != "1") {
            while (s.back() == '0') {
                s.pop_back();
                cnt++;
            }
            if (s.back() == '1' && s.length() > 1) {
                addOne(s);
                cnt++;
                continue;
            }
        }
        return cnt;
    }
};