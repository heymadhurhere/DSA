class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int total = accumulate(apple.begin(), apple.end(), 0);
        sort(capacity.rbegin(), capacity.rend());
        int cnt = 0;
        int sum = 0;
        for (int i = 0; i < capacity.size(); i++) {
            sum += capacity[i];
            cnt++;
            if (sum >= total) {
                return cnt;
            }
        }
        return cnt;
    }
};