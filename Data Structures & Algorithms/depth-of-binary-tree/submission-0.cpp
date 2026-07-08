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
    int maxDepth(TreeNode* root) {
        return depthFirstSearch(root);
    }

    int depthFirstSearch(TreeNode* node)
    {
        if(node == NULL) return 0;

        int leftNodeCount = depthFirstSearch(node->left);
        int rightNodeCount = depthFirstSearch(node->right);
        return std::max(leftNodeCount,rightNodeCount) + 1;
    }
};
