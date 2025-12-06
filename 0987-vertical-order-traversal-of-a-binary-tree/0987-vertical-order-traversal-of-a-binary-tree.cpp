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
    void traverse(TreeNode* root, int x, int y,
                  vector<pair<pair<int, int>, int>>& tmp) {
        if (root == NULL)
            return;

        traverse(root->left, x - 1, y + 1, tmp);
        tmp.push_back({{x, y}, root->val});
        traverse(root->right, x + 1, y + 1, tmp);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<pair<pair<int, int>, int>> tmp;
        int x = 0, y = 0;
        traverse(root, x, y, tmp);
        sort(tmp.begin(), tmp.end());
        map<int, vector<int>> mpp;
        for (auto it : tmp) {
            mpp[it.first.first].push_back(it.second);
        }
        vector<vector<int>> ans;
        for (auto it : mpp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};