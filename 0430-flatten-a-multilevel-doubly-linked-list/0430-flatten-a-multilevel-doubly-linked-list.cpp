/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head)
            return NULL;
        Node* ans = new Node(0);
        Node* tmp = ans;
        stack<Node*> st;
        st.push(head);

        while (!st.empty()) {
            Node* curr = st.top();
            st.pop();
            while (curr) {
                Node* newNode = new Node(curr->val);
                ans->next = newNode;
                newNode->prev = ans;
                newNode->child = NULL;
                ans = newNode;
                if (curr->child) {
                    if (curr->next)
                        st.push(curr->next);
                    curr = curr->child;
                } else
                    curr = curr->next;
            }
        }
        Node* res = tmp->next;
        if (res) {
            res->prev = NULL;
        }
        return res;
    }
};