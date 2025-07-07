class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        int n = events.size();
        int st = events[0][0], en = events[n - 1][1];
        priority_queue<int, vector<int>, greater<int>> pq;
        int i = 0;
        int cnt = 0;
        while (i < n || !pq.empty()) {
            while (i < n && events[i][0] == st) {
                pq.push(events[i][1]);
                i++;
            }
            if (!pq.empty()) {
                pq.pop();
                cnt++;
            }
            st++;
            while (!pq.empty() && pq.top() < st) {
                pq.pop();
            }
        }
        return cnt;
    }
};