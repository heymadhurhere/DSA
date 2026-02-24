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
    void solve(TreeNode* root, vector<string>& ans, string tmp) {
        if (root == NULL) {
            return;
        }
        tmp += char(root->val + '0');
        if (!root->left && !root->right) {
            ans.push_back(tmp);
            return;
        }
        solve(root->left, ans, tmp);
        solve(root->right, ans, tmp);
    }
    int sumRootToLeaf(TreeNode* root) {
        string tmp = "";
        vector<string> ans;
        solve(root, ans, tmp);
        int sum = 0;
        for (int i = 0; i < ans.size(); i++) {
            int num = stoi(ans[i], nullptr, 2);
            sum += num;
        }
        return sum;
    }
};