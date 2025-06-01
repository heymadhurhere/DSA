/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    
    bool getPath(TreeNode* root, vector<int>& arr, int x) {
        if (!root) {
            return false;
        }
        arr.push_back(root->val);
        if (root->val == x) {
            return true;
        }
        if (getPath(root->left, arr, x) || getPath(root->right, arr, x)) {
            return true;
        }
        arr.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<int> first;
        vector<int> second;

        int x = p->val;
        int y = q->val;

        getPath(root, first, x);
        getPath(root, second, y);

        reverse(first.begin(), first.end());
        reverse(second.begin(), second.end());

        bool found = false;
        int ans = 0;
        for (int i = 0; i < first.size(); ++i){
            for (int j = 0; j < second.size(); ++j){
                if (first[i] == second[j]){
                    ans = first[i];
                    found = true;
                    break;
                }
            }
            if (found) break;
        }

        TreeNode* temp = new TreeNode(ans);
        return temp;
    }
};