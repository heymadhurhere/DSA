class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), r = needle.size() - 1, i = 0;

        while (i + needle.size() - 1 < n) {
            if (haystack.substr(i, needle.size()) == needle) {
                return i;
            }
            i++;
        }

        return -1;
    }
};