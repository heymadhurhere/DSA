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
class BSTIterator {
public:
    queue<TreeNode*> q;
    void traverse(TreeNode* root, queue<TreeNode*>& q) {
        if (!root)
            return;

        traverse(root->left, q);
        q.push(root);
        traverse(root->right, q);
    }
    BSTIterator(TreeNode* root) { traverse(root, q); }

    int next() {
        int ans = q.front()->val;
        q.pop();
        return ans;
    }

    bool hasNext() {
        if (!q.empty())
            return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */