/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    class compare {
    public:
        bool operator()(ListNode* a, ListNode* b) { return a->val > b->val; }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        int n = lists.size();
        if (n == 0) return NULL;
        for (int i = 0; i < n; i++) {
            if (lists[i] != NULL)
            pq.push(lists[i]);
        }
        ListNode* temp = NULL;
        ListNode* head = NULL;
        while (pq.size() > 0) {
            ListNode* top = pq.top();
            pq.pop();
            if (top->next != NULL) {
                pq.push(top->next);
            }
            if (head == NULL) {
                head = top;
                temp = top;
            } else {
                temp->next = top;
                temp = top;
            }
        }
        return head;
    }
};