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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int, TreeNode*> mpp;
        unordered_set<int> children;
        for (vector<int>& d : descriptions) {
            int parent = d[0], child = d[1], isLeft = d[2];
            children.insert(child);
            TreeNode *par, *childN;
            if (mpp.find(parent) != mpp.end())
                par = mpp[parent];
            else {
                par = new TreeNode(parent);
                mpp[parent] = par;
            }

            if (mpp.find(child) != mpp.end())
                childN = mpp[child];
            else {
                childN = new TreeNode(child);
                mpp[child] = childN;
            }

            if (isLeft)
                par->left = childN;
            else
                par->right = childN;
        }

        for (auto [parent, node] : mpp) {
            if (children.find(parent) == children.end())
                return node;
        }
        return new TreeNode(-1);
    }
};