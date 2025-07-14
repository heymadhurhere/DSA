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
    int getDecimalValue(ListNode* head) {
        vector<int> temp;
        ListNode* it = head;
        while (it != NULL) {
            temp.push_back(it->val);
            it = it->next;
        }
        reverse(temp.begin(), temp.end());
        int ans = 0;
        for (int i = 0; i < temp.size(); i++) {
            ans += temp[i] * pow(2, i);
        }
        return ans;
    }
};