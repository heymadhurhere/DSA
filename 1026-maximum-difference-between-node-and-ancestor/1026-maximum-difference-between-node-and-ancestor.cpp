/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int v = INT_MIN;
    void dfs(TreeNode* root, int maxi, int mini) {
        // base case
        if (root == NULL) return;

        mini = min(mini, root->val);
        maxi = max(maxi, root->val);

        v = max(v, abs(maxi - mini));

        dfs(root->left, maxi, mini);
        dfs(root->right, maxi, mini);
    }
    int maxAncestorDiff(TreeNode* root) {
        int maxi = root->val, mini = root->val;
        dfs(root, maxi, mini);
        return v;
    }
};