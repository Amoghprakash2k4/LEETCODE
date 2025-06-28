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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> arr;
        if (root == nullptr) {
            return arr;
        }

        // Preorder: visit root first
        arr.push_back(root->val);

        // Traverse left subtree and collect values
        vector<int> left = preorderTraversal(root->left);

        // Traverse right subtree and collect values
        vector<int> right = preorderTraversal(root->right);

        // Append left subtree values
        arr.insert(arr.end(), left.begin(), left.end());

        // Append right subtree values
        arr.insert(arr.end(), right.begin(), right.end());

        return arr;
    }
};
