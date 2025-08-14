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
    int fn(int a, int b) {
        if (a >= 0 && b >= 0)
            return a + b;
        if (a * b > 0)
            return 0;
        return max(a, b);
    }
    int solve(TreeNode* root, int& ans) {
        if (root == NULL) {
            return 0;
        }
        int ls = solve(root->left, ans);
        int rs = solve(root->right, ans);
        ans = max(ans, fn(ls, rs) + root->val);
        return root->val + max(0, max(ls, rs));
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        solve(root, ans);
        return ans;
    }
};