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
    bool tra(TreeNode* root, long long minVal, long long maxVal) {
        if (!root) return true; // empty subtree is valid
        if (root->val <= minVal || root->val >= maxVal) return false;

        return tra(root->left, minVal, root->val) &&
               tra(root->right, root->val, maxVal);
    }

    bool isValidBST(TreeNode* root) {
        return tra(root, LLONG_MIN, LLONG_MAX);
    }
};
