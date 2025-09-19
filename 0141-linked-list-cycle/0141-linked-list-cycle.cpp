/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return false;
        ListNode* tmp1 = head;
        ListNode* tmp2 = head->next;
        while (true) {
            if (tmp1 == tmp2)
                return true;
            if (tmp1 == NULL || tmp2 == NULL)
                return false;
            tmp1 = tmp1->next;
            if (tmp2->next == NULL || tmp2->next->next == NULL)
                return false;
            tmp2 = tmp2->next->next;
        }
        return false;
    }
};