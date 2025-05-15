class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (auto it : tasks) {
            freq[it - 'A']++;
        }
        priority_queue<int> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) {
                pq.push(freq[i]);
            }
        }
        int cnt = 0;
        while (!pq.empty()) {
            int work = n + 1;
            vector<int> tmp;
            int wrkdone = 0;
            for (int i = 0; i < work && !pq.empty(); i++) {
                int num = pq.top();
                pq.pop();
                num--;
                if (num > 0) {
                    tmp.push_back(num);
                }
                wrkdone++;
            }

            for (auto it : tmp) {
                pq.push(it);
            }

            if (!pq.empty()) {
                cnt += work;
            } else {
                cnt += wrkdone;
            }
        }
        return cnt;
    }
};