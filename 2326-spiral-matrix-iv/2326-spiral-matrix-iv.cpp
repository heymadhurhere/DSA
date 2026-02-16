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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        int sRow = 0, sCol = 0, eRow = m - 1, eCol = n - 1;
        while (head != NULL) {
            // start row
            for (int i = sCol; i <= eCol && head != NULL; i++) {
                ans[sRow][i] = head->val;
                head = head->next;
            }
            sRow++;
            // end col
            for (int j = sRow; j <= eRow && head != NULL; j++) {
                ans[j][eCol] = head->val;
                head = head->next;
            }
            eCol--;
            // end row
            for (int i = eCol; i >= sCol && head != NULL; i--) {
                ans[eRow][i] = head->val;
                head = head->next;
            }
            eRow--;
            // start col
            for (int j = eRow; j >= sRow && head != NULL; j--) {
                ans[j][sCol] = head->val;
                head = head->next;
            }
            sCol++;
        }
        return ans;
    }
};