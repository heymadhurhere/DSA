class Solution {
public:
    string numtiplyStringWithNumber(string s, int num) {
        int n = s.length();
        string tmp = "";
        int carry = 0;
        for (int i = n - 1; i >= 0; i--) {
            int pro = (s[i] - '0') * num;
            pro += carry;
            carry = pro / 10;
            int to_insert = pro % 10;
            tmp.push_back(to_insert + '0');
        }
        if (carry != 0) {
            string tmp2 = to_string(carry);
            reverse(tmp2.begin(), tmp2.end());
            tmp += tmp2;
        }
        reverse(tmp.begin(), tmp.end());
        return tmp;
    }
    string addStrings(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;

        string result = "";

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if (i >= 0)
                sum += a[i--] - '0';
            if (j >= 0)
                sum += b[j--] - '0';

            result.push_back(char(sum % 10 + '0'));
            carry = sum / 10;
        }

        reverse(result.begin(), result.end());
        return result;
    }
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";

        int n1 = num1.size(), n2 = num2.size();

        string add = "";

        for (int i = n1 - 1; i >= 0; i--) {
            string tmp = numtiplyStringWithNumber(num2, num1[i] - '0');
            int zero = n1 - 1 - i;
            while (zero > 0) {
                tmp.push_back('0');
                zero--;
            }
            add = addStrings(add, tmp);
        }
        return add;
    }
};