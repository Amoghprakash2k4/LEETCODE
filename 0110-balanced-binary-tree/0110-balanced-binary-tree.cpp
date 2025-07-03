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
    int checkHeight(TreeNode* node) {
        if (!node) return 0;

        int left = checkHeight(node->left);
        if (left == -1) return -1;  // left subtree unbalanced

        int right = checkHeight(node->right);
        if (right == -1) return -1; // right subtree unbalanced

        if (abs(left - right) > 1) return -1; // current node unbalanced

        return max(left, right) + 1; // return height
    }

    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
};
