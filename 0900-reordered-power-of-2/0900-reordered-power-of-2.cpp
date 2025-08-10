class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        sort(s.begin(), s.end());
        string ori = s;
        if (s[0] != '0' && (stoi(s) & (stoi(s) - 1)) == 0)
            return true;
        next_permutation(s.begin(), s.end());
        while (s != ori) {
            if ((s[0] != '0' && (stoi(s) & (stoi(s) - 1)) == 0))
                return true;
            next_permutation(s.begin(), s.end());
        }
        return false;
    }
};