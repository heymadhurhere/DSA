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
    TreeNode* solve(vector<int>& inorder, int inStart, int inEnd,
                    vector<int>& postorder, int postStart, int postEnd,
                    map<int, int>& inMap) {
        if (postStart > postEnd || inStart > inEnd)
            return NULL;

        TreeNode* root = new TreeNode(postorder[postEnd]);

        int inRoot = inMap[postorder[postEnd]];
        int left = inRoot - inStart;

        root->left = solve(inorder, inStart, inRoot - 1, postorder, postStart,
                           postStart + left - 1, inMap);
        root->right = solve(inorder, inRoot + 1, inEnd, postorder,
                            postStart + left, postEnd - 1, inMap);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> inMap;
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            inMap[inorder[i]] = i;
        }
        TreeNode* root = solve(inorder, 0, n - 1, postorder, 0, n - 1, inMap);
        return root;
    }
};