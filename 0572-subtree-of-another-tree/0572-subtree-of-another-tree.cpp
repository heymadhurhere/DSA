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
    bool traverse(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot)
            return true;
        else {
            if (!root || !subRoot || root->val != subRoot->val) {
                return false;
            }
            return traverse(root->left, subRoot->left) &&
                   traverse(root->right, subRoot->right);
        }
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root)
            return false;
        if (traverse(root, subRoot))
            return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};