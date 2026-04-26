class Solution {
public:
    void solve(int idx, vector<int>& a, vector<vector<int>>& ans,
               vector<int>& curr) {
        if (idx == a.size()) {
            if (!curr.empty()) {
                ans.push_back(curr);
            }
            return;
        }

        curr.push_back(idx);
        solve(idx + 1, a, ans, curr);

        curr.pop_back();
        solve(idx + 1, a, ans, curr);
    }
    int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> adj(n);

        for (auto it : edges) {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<vector<int>> ans;
        vector<int> curr;

        solve(0, nums, ans, curr);
        int cnt = 0;

        // iterate in ans for each subset
        for (auto it : ans) {
            // for each subset, check the sum
            vector<int> tmp = it;
            int sum = 0;
            for (int i = 0; i < tmp.size(); i++) {
                sum += nums[tmp[i]];
            }
            if (sum % 2 != 0)
                continue;

            // if sum is even, make adjacency list and check number of
            // components subset basically contains the nodes
            vector<vector<int>> adj2(n);
            unordered_set<int> st(tmp.begin(), tmp.end());

            for (int i = 0; i < tmp.size(); i++) {
                int u = tmp[i];
                // check the nodes which are connected to the u node in the main
                // graph also present in the induced graph or not and if
                // present, then add it to the adj2

                for (int j = 0; j < adj[u].size(); j++) {
                    int el = adj[u][j];

                    if (st.count(el)) {
                        adj2[u].push_back(el);
                    }
                }
            }

            queue<int> q;
            unordered_set<int> vis;

            // Start BFS from the first node in our current subset
            q.push(tmp[0]);
            vis.insert(tmp[0]);

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int neighbor : adj2[node]) {
                    if (!vis.count(neighbor)) {
                        vis.insert(neighbor);
                        q.push(neighbor);
                    }
                }
            }

            if (vis.size() == tmp.size()) {
                cnt++;
            }
        }
        return cnt;
    }
};