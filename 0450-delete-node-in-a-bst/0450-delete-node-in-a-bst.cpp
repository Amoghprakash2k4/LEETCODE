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

TreeNode* findMin(TreeNode* node) {
    // Find the leftmost (minimum value) node in a BST
    while (node->left) node = node->left;
    return node;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return nullptr; // Base case: empty tree

    // Traverse to find the node with key
    if (key < root->val)
        root->left = deleteNode(root->left, key);
    else if (key > root->val)
        root->right = deleteNode(root->right, key);
    else {
        // Node found
        if (!root->left) {
            // Node has only right child or no child
            TreeNode* rightChild = root->right;
            delete root;
            return rightChild;
        } else if (!root->right) {
            // Node has only left child
            TreeNode* leftChild = root->left;
            delete root;
            return leftChild;
        } else {
            // Node has two children: replace with inorder successor
            TreeNode* minNode = findMin(root->right);
            root->val = minNode->val;
            root->right = deleteNode(root->right, minNode->val);
        }
    }
    return root;
}
};