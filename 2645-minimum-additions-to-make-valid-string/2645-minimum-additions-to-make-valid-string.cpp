class Solution {
public:
    int addMinimum(string word) {
        int n = word.length();
        if (n == 1)
            return 2;

        int cnt = 0;
        if (word[0] == 'b')
            cnt++;
        if (word[0] == 'c')
            cnt += 2;
        for (int i = 1; i < n; i++) {
            // case 1: last char is a
            if (word[i - 1] == 'a') {
                // case 1.1 present char is b
                if (word[i] == 'b') {
                    // do nothing
                }
                // case 1.2 present char is c
                else if (word[i] == 'c') {
                    // insert b
                    cnt++;
                }
                // case 1.3 present char is a
                else if (word[i] == 'a') {
                    // insert bc
                    cnt += 2;
                }
            }
            // case 2: last char is b
            else if (word[i - 1] == 'b') {
                // case 2.1 present char is a
                if (word[i] == 'a') {
                    // insert c
                    cnt++;
                }
                // case 2.2 present char is b
                else if (word[i] == 'b') {
                    // insert ca
                    cnt += 2;
                }
                // case 2.3 present char is c
                else if (word[i] == 'c') {
                    // do nothing
                }
            }
            // case 3: last char is c
            else if (word[i - 1] == 'c') {
                // case 3.1 present char is a
                if (word[i] == 'a') {
                    // do nothing
                }
                // case 3.2 present char is b
                else if (word[i] == 'b') {
                    // insert a
                    cnt++;
                }
                // case 3.3 present char is c
                else if (word[i] == 'c') {
                    // insert ab
                    cnt += 2;
                }
            }
        }
        // check on last char
        if (word[n - 1] == 'a')
            cnt += 2;
        else if (word[n - 1] == 'b')
            cnt += 1;
        return cnt;
    }
};