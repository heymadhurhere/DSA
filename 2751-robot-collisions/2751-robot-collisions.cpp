class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string directions) {
        int n = positions.size();

        vector<tuple<int, int, char, int>> robots;
        for (int i = 0; i < n; i++) {
            robots.push_back({positions[i], healths[i], directions[i], i});
        }

        sort(robots.begin(), robots.end());

        vector<int> newHealths(n);
        string newDirections(n, ' ');
        vector<int> indexMap(n);

        for (int i = 0; i < n; i++) {
            newHealths[i] = get<1>(robots[i]);
            newDirections[i] = get<2>(robots[i]);
            indexMap[i] = get<3>(robots[i]);
        }

        stack<pair<int, pair<int, char>>> st1; //{idx, {health, direction}}
        vector<int> ans(n, 0);

        for (int k = 0; k < n; k++) {
            st1.push({k, {newHealths[k], newDirections[k]}});
        }

        stack<pair<int, pair<int, char>>> st2;
        if (!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }

        while (!st1.empty()) {
            if (!st1.empty() and !st2.empty() and
                st1.top().second.second == 'R' &&
                st2.top().second.second == 'L') {
                if (st1.top().second.first < st2.top().second.first) {
                    st1.pop();
                    st2.top().second.first--;
                    if (st2.top().second.first == 0) {
                        st2.pop();
                    }
                } else if (st1.top().second.first > st2.top().second.first) {
                    st2.pop();
                    st1.top().second.first--;
                    if (st1.top().second.first == 0) {
                        st1.pop();
                    }
                } else if (st1.top().second.first == st2.top().second.first) {
                    st1.pop();
                    st2.pop();
                }
            } else {
                if (!st1.empty()) {
                    st2.push(st1.top());
                    st1.pop();
                }
            }
        }
        while (!st2.empty()) {
            int idx = st2.top().first;
            int life = st2.top().second.first;
            ans[indexMap[idx]] = life;
            st2.pop();
        }

        vector<int> final_ans;
        for (int i = 0; i < n; i++) {
            if (ans[i] > 0) {
                final_ans.push_back(ans[i]);
            }
        }

        return final_ans;
    }
};