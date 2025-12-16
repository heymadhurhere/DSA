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
    void traverse(TreeNode* root, vector<int>& tmp) {
        if (!root)
            return;

        traverse(root->left, tmp);
        tmp.push_back(root->val);
        traverse(root->right, tmp);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> tmp;
        traverse(root, tmp);
        int n = tmp.size();
        int l = 0, r = n - 1;

        while (l < r) {
            if (tmp[l] + tmp[r] == k)
                return true;
            else if (tmp[l] + tmp[r] > k)
                r--;
            else
                l++;
        }
        return false;
    }
};