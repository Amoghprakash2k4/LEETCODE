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
    bool check(TreeNode* node, TreeNode* subRoot){
        if(!node && !subRoot) return true;
        if(!node || !subRoot) return false;
        if(node->val != subRoot->val) return false;

        return check(node->left, subRoot->left) && check(node->right, subRoot->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;

        if(root->val == subRoot->val && check(root, subRoot))
            return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right , subRoot);
    }
};