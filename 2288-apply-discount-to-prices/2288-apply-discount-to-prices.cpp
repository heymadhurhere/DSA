class Solution {
public:
    bool isPrice(string s) {
        int n = s.length();
        if (n == 1)
            return false;

        if (s[0] == '$') {
            for (int i = 1; i < n; i++) {
                if (s[i] < '0' || s[i] > '9')
                    return false;
            }
            return true;
        }
        return false;
    }
    long long convert_to_price(string s) {
        long long num = 0;
        int n = s.length();
        for (int i = 1; i < n; i++) {
            int dig = s[i] - '0';
            num = num * 10 + dig;
        }
        return num;
    }
    string toTwoDecimal(double x) {
        ostringstream oss;
        oss << fixed << setprecision(2) << x;
        return oss.str();
    }
    string discountPrices(string sentence, int discount) {
        stringstream ss(sentence);
        string word;
        string ans;

        while (ss >> word) {
            if (isPrice(word)) {
                long long price = convert_to_price(word);
                double discounted_price = (price * (100.0 - discount)) / 100.0;
                string val = toTwoDecimal(discounted_price);
                ans += '$';
                ans += val;
                ans += ' ';
            } else {
                ans += word;
                ans += ' ';
            }
        }
        ans.pop_back();
        return ans;
    }
};