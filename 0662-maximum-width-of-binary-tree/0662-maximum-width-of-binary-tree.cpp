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
    int levelOrder(TreeNode* root) {
        if (root == NULL)
            return 0;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int maxWid = INT_MIN;

        while (!q.empty()) {
            int left = q.front().second;
            int right = q.back().second;
            int wid = right - left + 1;
            maxWid = max(maxWid, wid);

            int n = q.size();

            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front().first;
                long long pos = q.front().second - left;
                q.pop();
                if (node->left) {
                    q.push({node->left, pos * 2});
                }

                if (node->right) {
                    q.push({node->right, pos * 2 + 1});
                }
            }
        }
        return maxWid;
    }
    int widthOfBinaryTree(TreeNode* root) { return levelOrder(root); }
};