/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    vector<string> tmp;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // level order;
        tmp.clear();
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node == NULL)
                tmp.push_back("#");
            else
                tmp.push_back(to_string(node->val));

            if (node != NULL) {
                q.push(node->left);
                q.push(node->right);
            }
        }
        string ans = "";
        int n = tmp.size();

        for (int i = 0; i < n; i++) {
            if (tmp[i] == "#") {
                ans += "null,";
            } else {
                ans += tmp[i] + ",";
            }
        }
        ans.pop_back();
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0)
            return NULL;

        tmp.clear();
        string curr = "";
        for (char c : data) {
            if (c == ',') {
                tmp.push_back(curr == "null" ? "#" : curr);
                curr = "";
            } else {
                curr += c;
            }
        }

        if (!curr.empty()) {
            tmp.push_back(curr == "null" ? "#" : curr);
        }

        if (tmp[0] == "#")
            return NULL;
        TreeNode* root = new TreeNode(stoi(tmp[0]));
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;

        while (!q.empty() && i < tmp.size()) {

            TreeNode* node = q.front();
            q.pop();

            if (tmp[i] != "#") {
                node->left = new TreeNode(stoi(tmp[i]));
                q.push(node->left);
            } else {
                node->left = NULL;
            }
            i++;

            if (i < tmp.size() && tmp[i] != "#") {
                node->right = new TreeNode(stoi(tmp[i]));
                q.push(node->right);
            } else {
                node->right = NULL;
            }
            i++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));