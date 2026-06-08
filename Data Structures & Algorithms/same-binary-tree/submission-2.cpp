/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
   public:
    bool areTheyEqual = true;
    bool isSameTree(TreeNode* p, TreeNode* q) {
        dfs(p, q);
        return areTheyEqual;
    }

    void dfs(TreeNode* pNode, TreeNode* qNode) {
        if (pNode == NULL && qNode == NULL) return;
        if (pNode == NULL && qNode != NULL) {
            areTheyEqual = false;
            return;
        }
        if (pNode != NULL && qNode == NULL) {
            areTheyEqual = false;
            return;
        }

        TreeNode *pNext, *qNext;

        pNext = pNode->left;
        qNext = qNode->left;
        std::cout << "p->next and q->next";
        dfs(pNext, qNext);

        pNext = pNode->right;
        qNext = qNode->right;
        std::cout << "p->next and q->next";
        dfs(pNext, qNext);

        std::cout << "comparing : " << pNode->val << " and " << qNode->val;
        if (pNode->val != qNode->val) {
            areTheyEqual = false;
            return;
        } else
            return;
    }
};
