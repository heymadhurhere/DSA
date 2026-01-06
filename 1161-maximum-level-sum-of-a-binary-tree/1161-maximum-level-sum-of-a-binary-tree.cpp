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
    int maxLevelSum(TreeNode* root) {
        long long sum = root->val;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        int lev = 1;
        while (!q.empty()) {
            int n = q.size();
            long long tmp = 0;
            int pl = q.front().second;
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front().first;
                q.pop();
                tmp += node->val;
                if (node->left) {
                    q.push({node->left, pl + 1});
                }
                if (node->right) {
                    q.push({node->right, pl + 1});
                }
            }
            if (tmp > sum) {
                sum = tmp;
                lev = pl;
            }
        }
        return lev;
    }
};