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
struct NodeValue {
    int sum;
    bool isBst;
    int minVal, maxVal;

    NodeValue(int sum, bool isBst, int minVal, int maxVal) {
        this->sum = sum;
        this->isBst = isBst;
        this->minVal = minVal;
        this->maxVal = maxVal;
    }
};

class Solution {
public:
    int maxi = 0;
    NodeValue maxSum(TreeNode* root) {
        if (!root) {
            return NodeValue(0, true, INT_MAX, INT_MIN);
        }
        auto left = maxSum(root->left);
        auto right = maxSum(root->right);

        if (left.isBst && right.isBst && left.maxVal < root->val &&
            right.minVal > root->val) {
            int currSum = left.sum + right.sum + root->val;
            maxi = max(maxi, currSum);
            return NodeValue(currSum, true, min(root->val, left.minVal),
                             max(root->val, right.maxVal));
        }

        return NodeValue(0, false, INT_MIN, INT_MAX);
    }
    int maxSumBST(TreeNode* root) {
        maxSum(root);
        return maxi;
    }
};