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
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;
    TreeNode* prev;
    void inOrder(TreeNode* root) {
        if (!root)
            return;
        inOrder(root->left);
        if (prev && root->val < prev->val) {
            if (!first) {
                first = prev;
                middle = root;
            } else
                last = root;
        }
        prev = root;
        inOrder(root->right);
    }
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        inOrder(root);
        if (first && last)
            swap(first->val, last->val);
        else if (first && middle)
            swap(first->val, middle->val);
    }
};