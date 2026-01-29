/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
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
    void dfs(int node, int parent, int dist, int k,
             unordered_map<int, vector<int>>& adj, vector<int>& res) {
        if (dist == k) {
            res.push_back(node);
            return;
        }

        for (int nei : adj[node]) {
            if (nei == parent)
                continue;
            dfs(nei, node, dist + 1, k, adj, res);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int, vector<int>> adj;
        adjMake(root, adj);
        vector<int> res;
        dfs(target->val, -1, 0, k, adj, res);
        return res;
    }
};