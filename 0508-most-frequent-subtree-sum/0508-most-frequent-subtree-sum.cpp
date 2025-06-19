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
    int solve(unordered_map<int, int>& mpp, TreeNode* root, int sum) {
        if (!root) {
            return 0;
        }
        int left = solve(mpp, root->left, sum);
        int right = solve(mpp, root->right, sum);
        int add = root->val + left + right;
        mpp[add]++;
        return add;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> mpp;
        int sum = 0;
        solve(mpp, root, sum);
        int maxi = INT_MIN;
        for (auto& it : mpp) {
            maxi = max(maxi, it.second);
        }
        vector<int> ans;
        for (auto& it : mpp) {
            if (it.second == maxi) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};