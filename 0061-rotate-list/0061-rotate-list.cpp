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
public:
    int getLength(ListNode* head) {
        int cnt = 0;
        while (head != NULL) {
            head = head->next;
            cnt++;
        }
        return cnt;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int len = getLength(head);
        if (head == NULL || head->next == NULL) return head;
        if (k % len == 0)
            return head;
        int rem = k % len;
        int front = len - rem;
        ListNode* tmp = head;
        int cnt = 1;
        while (cnt < front) {
            tmp = tmp->next;
            cnt++;
        }
        ListNode* ptr = tmp->next;
        tmp->next = NULL;
        ListNode* tmp2 = ptr;
        while (tmp2->next != NULL) {
            tmp2 = tmp2->next;
        }
        tmp2->next = head;
        return ptr;
    }
};