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
    bool traverse(TreeNode* root, vector<TreeNode*>& ans, TreeNode* node) {
        if (root == NULL)
            return false;
        ans.push_back(root);
        if (root == node)
            return true;
        if (traverse(root->left, ans, node) ||
            traverse(root->right, ans, node)) {
            return true;
        }
        ans.pop_back();
        return false;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        vector<TreeNode*> lastLev;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<TreeNode*> tmp;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                tmp.push_back(node);
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            lastLev = tmp;
        }
        if (lastLev.size() == 1) {
            return lastLev[0];
        }
        vector<vector<TreeNode*>> nodes;
        for (int i = 0; i < lastLev.size(); i++) {
            vector<TreeNode*> tmp;
            bool check = traverse(root, tmp, lastLev[i]);
            nodes.push_back(tmp);
        }

        TreeNode* ans = NULL;
        int size = INT_MAX;
        for (int i = 0; i < nodes.size(); i++) {
            size = min(size, (int)nodes[i].size());
        }

        bool flag = false;

        for (int c = 0; c < size; c++) {
            TreeNode* tmp = nodes[0][c];
            for (int r = 1; r < nodes.size(); r++) {
                if (nodes[r][c] != tmp) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                ans = tmp;
            } else
                break;
        }
        return ans;
    }
};