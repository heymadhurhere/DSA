class Solution {
public:
#define ll long long
    int findNthDigit(int k) {
        ll dig_len = 1;
        ll cnt = 9;
        ll s = 1;

        while (k > s + cnt * dig_len - 1) {
            s += cnt * dig_len;
            dig_len++;
            cnt *= 10;
        }

        ll f_num = pow(10, dig_len - 1);
        ll n_off = (k - s) / dig_len;
        ll t_num = f_num + n_off;

        string num_str = to_string(t_num);
        ll dig_off = k - s;
        ll pos_in_num = dig_off % dig_len;

        return (int)num_str[pos_in_num] - '0';
    }
};