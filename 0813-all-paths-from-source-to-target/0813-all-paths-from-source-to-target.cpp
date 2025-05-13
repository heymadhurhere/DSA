class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& ans,
             vector<int>& temp, int target, int node) {
        temp.push_back(node);
        if (node == target) {
            ans.push_back(temp);
        }
        for (auto it : graph[node]) {
            dfs(graph, ans, temp, target, it);
        }
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(graph, ans, temp, n - 1, 0);
        return ans;
    }
};