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
    const int MOD = 1e9 + 7;
    void function(TreeNode* root, int& total_sum,
                  unordered_map<TreeNode*, int>& subtreeSum) {
        if (root == NULL)
            return;
        function(root->left, total_sum, subtreeSum);
        function(root->right, total_sum, subtreeSum);
        total_sum += root->val;
        subtreeSum[root] = (root->left == NULL ? 0 : subtreeSum[root->left]) +
                           (root->right == NULL ? 0 : subtreeSum[root->right]) +
                           root->val;
    }
    int maxProduct(TreeNode* root) {
        int total_sum = 0;
        unordered_map<TreeNode*, int> subTreeSum;
        function(root, total_sum, subTreeSum);
        long long ans = 0;
        for (auto& it : subTreeSum) {
            int tmp = total_sum - it.second;
            ans = max(ans, (1LL * tmp * it.second));
        }
        return ans % MOD;
    }
};