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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* dummy = NULL;
        while (curr != NULL) {
            dummy = curr->next;
            curr->next = prev;
            prev = curr;
            curr = dummy;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return true;
        ListNode* ptr1 = head;
        ListNode* ptr2 = head;
        while (ptr2 != NULL) {
            if (ptr2->next == NULL || ptr2->next->next == NULL)
                break;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next->next;
        }
        ptr1->next = reverseList(ptr1->next);
        ListNode* tmp = ptr1->next;
        while (tmp != NULL) {
            if (head->val != tmp->val)
                return false;
            head = head->next;
            tmp = tmp->next;
        }
        return true;
    }
};