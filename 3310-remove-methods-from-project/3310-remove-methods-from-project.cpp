class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& e) {
        vector<vector<int>> adj(n);
        for (auto& it : e) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }
        queue<int> q;
        vector<bool> sus(n, false);

        q.push(k);
        sus[k] = true;
        // BFS from k and mark all nodes possible to be visited from k as
        // suspicious
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto& it : adj[u]) {
                if (!sus[it]) {
                    q.push(it);
                    sus[it] = true;
                }
            }
        }

        // again start BFS from k and check if any  node is true, if it is, then
        // our answer will contain all the nodes as answer and if not, then we
        // will return only those nodes which have value false

        bool flag = false;

        for (auto& it : e) {
            int u = it[0];
            int v = it[1];

            if (!sus[u] && sus[v]) {
                flag = true;
                break;
            }
        }

        vector<int> ans;

        if (flag) {
            for (int i = 0; i < n; i++) {
                ans.push_back(i);
            }
            return ans;
        }

        for (int i = 0; i < n; i++) {
            if (!sus[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};