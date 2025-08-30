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
    int getLen(ListNode* head) {
        int ans = 0;
        while (head != NULL) {
            ans++;
            head = head->next;
        }
        return ans;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int pos = getLen(head) - n + 1;
        if (pos == 1) {
            return head->next;
        }
        int cnt = 1;
        ListNode* ans = head;
        while (cnt != pos - 1) {
            head = head->next;
            cnt++;
        }
        head->next = head->next->next;
        return ans;
    }
};