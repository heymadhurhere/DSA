class Solution {
public:
    int solve(int idx, int pts, vector<string>& words, vector<vector<int>> dp,
              vector<char>& letters, vector<int>& score, vector<int> freq) {
        if (idx == words.size()) {
            return pts;
        }
        if (dp[idx][pts] != -1) {
            return dp[idx][pts];
        }
        int notPick = solve(idx + 1, pts, words, dp, letters, score, freq);
        vector<int> newFreq = freq;
        int currpts = 0;
        bool canInsert = true;
        for (auto ch : words[idx]) {
            if (newFreq[ch - 'a'] == 0) {
                canInsert = false;
                break;
            }
            newFreq[ch - 'a']--;
            currpts += score[ch - 'a'];
        }
        int pick = 0;
        if (canInsert)
            pick = currpts +
                   solve(idx + 1, pts, words, dp, letters, score, newFreq);
        return dp[idx][pts] = max(pick, notPick);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters,
                      vector<int>& score) {
        vector<int> freq(26, 0);
        for (auto it : letters) {
            freq[it - 'a']++;
        }
        int pts = 0;
        for (int i = 0; i < 26; i++) {
            pts += freq[i] * score[i];
        }
        int n = words.size();
        vector<vector<int>> dp(n + 1, vector<int>(pts + 1, -1));

        return solve(0, 0, words, dp, letters, score, freq);
    }
};