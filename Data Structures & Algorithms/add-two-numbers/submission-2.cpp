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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* retHead = new ListNode();
        ListNode* retTemp = retHead;

        ListNode *t1, *t2;
        t1 = l1;
        t2 = l2;

        int carry = 0;
        int sum;
        int firstFlag = 0;
        while (t1 != NULL && t2 != NULL) {
            sum = t1->val + t2->val + carry;
            if (sum >= 10) {
                carry = 1;
                sum = sum - 10;
            } else
                carry = 0;

            t1 = t1->next;
            t2 = t2->next;
            if (!firstFlag) {
                retTemp->val = sum;
                retTemp->next = NULL;
                firstFlag = 1;
            } else {
                ListNode* newNode = new ListNode();
                newNode->val = sum;
                newNode->next = NULL;

                retTemp->next = newNode;
                retTemp = newNode;
            }
        }
        ListNode* remains;
        if (t1 == NULL) {
            remains = t2;
        } else {
            remains = t1;
        }

        while (remains != NULL) {
            sum = remains->val + carry;
            if (sum >= 10) {
                carry = 1;
                sum = sum - 10;
            } else
                carry = 0;

            remains = remains->next;
            ListNode* newNode = new ListNode();
            newNode->val = sum;
            newNode->next = NULL;

            retTemp->next = newNode;
            retTemp = newNode;
        }

        if (carry) {
            ListNode* newNode = new ListNode();
            newNode->val = 1;
            newNode->next = NULL;

            retTemp->next = newNode;
            retTemp = newNode;
        }
        return retHead;
    }
};
