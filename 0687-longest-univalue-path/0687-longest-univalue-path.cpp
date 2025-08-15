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
    int solve(TreeNode* root, TreeNode* prnt, int& ans) {
        if (root == NULL) return 0;
        int l = solve(root->left, root, ans);
        int r = solve(root->right, root, ans);
        int left = 0, right = 0;
        if (root->left && root->left->val == root->val) {
            left = l;
        }
        if (root->right && root->right->val == root->val) {
            right = r;
        }
        ans = max(ans, left + right);
        return 1 + max(left, right);
    }
    int longestUnivaluePath(TreeNode* root) {
        if (!root) return 0;
        int ans = INT_MIN;
        solve(root, NULL, ans);
        return ans;
    }
};