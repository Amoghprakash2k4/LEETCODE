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
    // Find the rightmost (maximum value) node in a BST
    TreeNode* findMax(TreeNode* node) {
        while (node->right) node = node->right;
        return node;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } 
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } 
        else {
            // Node to delete found
            if (!root->left) {
                TreeNode* rightChild = root->right;
                delete root;
                return rightChild;
            } 
            else if (!root->right) {
                TreeNode* leftChild = root->left;
                delete root;
                return leftChild;
            } 
            else {
                // Node has two children → use inorder predecessor
                TreeNode* maxNode = findMax(root->left);
                root->val = maxNode->val;
                root->left = deleteNode(root->left, maxNode->val);
            }
        }
        return root;
    }
};
