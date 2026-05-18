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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        std::vector<ListNode*> qst;
        ListNode* tmp = head;
        while (tmp != nullptr) {
            qst.push_back(tmp);
            tmp = tmp->next;
        }
        int left=0;
        int right = qst.size() - 1;

        while(left < right){
            qst[left] -> next = qst[right];
            left++;

            if(left == right) break;

            qst[right]->next = qst[left];
            right--;
        }
        qst[left]->next = nullptr;
    }
};
