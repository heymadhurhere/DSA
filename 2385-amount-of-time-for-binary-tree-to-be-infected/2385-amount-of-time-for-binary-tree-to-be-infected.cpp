/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int ans = INT_MIN;
    void adjMake(TreeNode* root, unordered_map<int, vector<int>>& adj) {
        if (!root)
            return;
        if (root->left) {
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
            adjMake(root->left, adj);
        }
        if (root->right) {
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
            adjMake(root->right, adj);
        }
    }
    void dfs(int node, int parent, int dist,
             unordered_map<int, vector<int>>& adj) {
        ans = max(ans, dist);

        for (auto nei : adj[node]) {
            if (nei == parent)
                continue;
            dfs(nei, node, dist + 1, adj);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> adj;
        adjMake(root, adj);
        dfs(start, -1, 0, adj);
        return ans;
    }
};