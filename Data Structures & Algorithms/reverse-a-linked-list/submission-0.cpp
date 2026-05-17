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
        if (head == NULL) return head;

        ListNode* tmp = head;
        ListNode* prev;
        int flag = 0;
        while (tmp != NULL) {
            ListNode* current = new ListNode();
            current->val = tmp->val;
            if (flag == 0) {
                current->next = nullptr;
                flag=1;
            }
            else
            {
                current->next = prev;
            }
            tmp = tmp->next;
            prev = current;
        }
        delete(head);
        delete(tmp);
        return prev;
    }
};
