class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if (a)
            pq.push({a, 'a'});
        if (b)
            pq.push({b, 'b'});
        if (c)
            pq.push({c, 'c'});

        string ans = "";

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int f1 = it.first;
            char ch1 = it.second;

            if (ans.length() >= 2 && ans[ans.length() - 1] == ch1 &&
                ans[ans.length() - 2] == ch1) {
                // last two characters are equal
                if (pq.empty())
                    break; // stop if nothing left
                auto sec = pq.top();
                pq.pop();
                int f2 = sec.first;
                char ch2 = sec.second;
                ans += ch2;
                f2--;
                if (f2 > 0) {
                    pq.push({f2, ch2});
                }
                pq.push({f1, ch1});
            } else {
                ans += ch1;
                f1--;
                if (f1 > 0) {
                    pq.push({f1, ch1});
                }
            }
        }
        return ans;
    }
};