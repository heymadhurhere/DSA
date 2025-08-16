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
    int solve(TreeNode* root, long long sum, int tgt) {
        if (root == NULL)
            return 0;
        sum += root->val;
        int cnt = (sum == tgt) ? 1 : 0;
        cnt += solve(root->left, sum, tgt);
        cnt += solve(root->right, sum, tgt);

        return cnt;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if (root == NULL)
            return 0;
        return solve(root, 0LL, targetSum) + pathSum(root->left, targetSum) +
               pathSum(root->right, targetSum);
    }
};